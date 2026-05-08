#include <map>
#include <string>
#include <vector>

struct Node {
    std::map<std::string, Node> children;
};

class Tree {
private:
    Node root;

public:
    bool Has(const std::vector<std::string>& node) const;
    void Insert(const std::vector<std::string>& node);
    void Delete(const std::vector<std::string>& node);
};

bool Tree::Has(const std::vector<std::string>& node)const{

    //берем адрес папки, изначально корневой
    const Node* current = &root;
    
    for(size_t i = 0; i != node.size(); ++i){

        //it - адрес папки, в которой мы нашли (если нашли) имя папки {node[i]}
        auto it = current->children.find(node[i]);
        
        if(it == current->children.end()){
            return false;
        }

        // теперь заходим глубже - мы нашли в корневой папке папку с именем "node[i]",  
        // заходим в её node через it->second и помещаем адрес этого node (адрес найденнйо папки) в current,
        // так как curret - указатель
        current = &(it->second);
        
    }
    return true;

} 

void Tree::Insert(const std::vector<std::string>& node){

    // Создаем указатель на ссылку root
    Node* current = &root;

    for(size_t i = 0; i != node.size(); ++i){

        // Создаем итератор на найденный или не найденный ключ в папке
        auto it = current->children.find(node[i]);
        // Если ключ не был найден - вставляем пустую папку (как пару ключ-значение)
        if(it == current->children.end()){
            // Изначально я написал auto [it, has_been_inserted]
            // Но тогда создается новая переменная it локально в нутри условия if
            // А не как я хотел переобозначается моя старая переменная it
            // ______________________________________________________________________________
            // СНАЧАЛА Я НАПИСАЛ ТАК: 
            // auto [help_it, has_been_inserted] = current->children.insert({node[i], new_node}); 
            // НО ЭТО ТРЕБУЕТ ПРЕДВАРИТЕЛЬНОГО СОЗДАНИЯ new_node.(Закоментированно выше)
            // Можно лучше:
            auto [help_it, has_been_inserted] = current->children.try_emplace(node[i]);
            it = help_it;
        }

        current = &(it->second);

    }
}

void Tree::Delete(const std::vector<std::string>& node){

    Node* current = &root;

    for(size_t i = 0; i != node.size(); ++i){

        auto it = current->children.find(node[i]);
        if(it == current->children.end()){
            break;
        }
        if(i+1 == node.size()){
            current->children.erase(it);
        }else{
            current = &(it->second);
        }
         
    }
}
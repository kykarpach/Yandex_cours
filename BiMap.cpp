#include <stdexcept>
#include <optional>
#include <map>
#include <list>

template <typename Key1, typename Key2, typename Value>
class BiMap {
private:

    std::list<Value> V;

    std::map<Key1, Value*> primary_map;
    std::map<Key2, Value*> secondary_map;
    
public:

    BiMap() = default; 

    // Вставить значение, указав один или оба ключа.
    // Генерирует исключение std::invalid_argument("some text") в случае,
    // если оба ключа пусты, либо один из ключей уже имеется в хранилище.

    void Insert(const std::optional<Key1>& key1, const std::optional<Key2>& key2, const Value& value){

        // Проверка на пустоту обоих кл.чей
        if(!(key1) && !(key2)){
            throw std::invalid_argument("some text");
        }

        // Проверка на то, что переданный ключ уже существует, а так же на то что нам вообще передали ключ в std::optional  
        if( ( key1 && primary_map.count(*key1) ) || ( key2 && secondary_map.count(*key2) ) ){
            throw std::invalid_argument("some text");
        }

        V.push_front(value);

        if(key1){
            primary_map.insert({*key1, &V.front()});
        }
        if(key2){
            secondary_map.insert({*key2, &V.front()});
        }
        
    }

    // Получить значение по ключу первого типа.
    // Генерирует исключение std::out_of_range("some text")
    // в случае отсутствия ключа (как и функция at в std::map).

    Value& GetByPrimaryKey(const Key1& key){
        return *primary_map.at(key);
    }
    const Value& GetByPrimaryKey(const Key1& key) const{
        return *primary_map.at(key);
    }

    // Аналогичная функция для ключа второго типа.
    Value& GetBySecondaryKey(const Key2& key){
        return *secondary_map.at(key);
    }
    const Value& GetBySecondaryKey(const Key2& key) const{
        return *secondary_map.at(key);
    }
};


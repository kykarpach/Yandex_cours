#include <vector>


template <typename T>
class Table{
private:
    
    std::vector<std::vector<T>> table;

public:

    Table() = default;
    Table(size_t i, size_t j): table(i, std::vector<T>(j, T())){// T() - Значение по умолчанию типа T
    }

    std::vector<T>& operator [] (size_t i){
        return table[i];
    }

    const std::vector<T>& operator [] (size_t i) const{
        return table[i];
    }

    void resize(size_t i, size_t j){
        
        table.resize(i);

        for(size_t k = 0; k != table.size(); ++k){
            table[k].resize(j);
        }
    }

    std::pair<size_t, size_t> size()const{

        if(table.empty()){
            return {0, 0};
        }else if(!(table.empty()) && table[0].empty()){
            return {table.size(), 0};
        }else{
            return {table.size(), table[0].size()};
        }
    }

};


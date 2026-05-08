#include <vector>
#include <iostream>


template <typename T>
class AdvancedVector{
private:

    std::vector<T> vec;

public:

    AdvancedVector(){}

    AdvancedVector(const std::vector & v){

    }

    operator [](const T& n) const{
        
        if(n < nullptr && (-n) < vec.size() ){

            return vec[vec.size() - n];

        }else if((-n) >= vec.size()){

            return std::out_of_range;
        }

        if(n >= nullptr && n < vec.size()){
            
            return vec[n];

        }else if(n < vec.size()){

            return std::out_of_range;
        }

    }

    operator [](T& n){
        
        if(n < nullptr && (-n) < vec.size() ){

            return vec[vec.size() - n];

        }else if((-n) >= vec.size()){

            return std::out_of_range;
        }

        if(n >= nullptr && n < vec.size()){
            
            return vec[n];

        }else if(n < vec.size()){
            
            return std::out_of_range;
        }

    }

};


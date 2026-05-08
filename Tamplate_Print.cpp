#include <iostream>

template <typename container, typename separator>
void Print(const container& cont, const separator& sep){
    
    auto it = std::begin(cont);

    if(it != std::end(cont)){
        std::cout << *it;
        ++it;
    }

    for( ; it != std::end(cont); ++it){
        std::cout << sep << *it;
    }
    std::cout << "\n";
}
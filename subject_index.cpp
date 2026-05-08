#include <iostream>
#include <map>
#include <set>
#include <string>


int main(){

    size_t n;
    std::map<int, std::set<std::string>> page_and_word; //спросить про шортИнт
    int current_int;
    std::string current_str;

    std::cin >> n;

    for(size_t i = 0; i != n; ++i){
        
        std::cin >> current_str >> current_int;
        
        page_and_word[current_int].insert(current_str); //Это сумасшедшая хуня
    }

    for(const auto& [INT,WORD] : page_and_word){

        std::cout << INT;
        
        for(const auto& friendly_thug_52_NGG : WORD){
            std::cout << " " << friendly_thug_52_NGG;
        }
        
        std::cout << "\n";
    }
}
#include <iostream>
#include <set>
#include <unordered_set>

int main(){

    
    std::set<char> common;
    std::string word;

    std::cin >> word;
    for(char ch : word){
        common.insert(ch);
    }

    while(std::cin >> word){

        std::unordered_set<char> current(word.begin(), word.end());
        std::set<char> new_common;

        for(char ch : common){
            if(current.contains(ch)){
                new_common.insert(ch);
            }
        }
        common = new_common;
        
    }

    for(auto& key : common){
        std::cout << key;
    }
}
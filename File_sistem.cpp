#include <set>
#include <unordered_set>
#include <iostream>
#include <string>

int main(){

    std::string str;
    std::set<std::string> answer;

    while(std::cin >> str){

        size_t pos = 0;
        std::string path;

        while((pos = str.find('/', pos)) != std::string::npos){
            path = str.substr(0, pos);
            answer.insert(path + "/");

            ++pos;
        }
        
    }

    for(const auto& a : answer){
        std::cout << a << '\n';
    }
}
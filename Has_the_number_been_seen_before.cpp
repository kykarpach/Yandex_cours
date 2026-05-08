#include <iostream>
#include <string>
#include <set>
#include <list>

int main(){

    std::set<int> numbers;
    std::list<std::string> Yes_No;
    int number;
    while(std::cin >> number){
        auto [key, answer] = numbers.insert(number);
        if(answer){
            Yes_No.push_back("NO");
        }
        else{
            Yes_No.push_back("YES");
        }

    }

    for(const auto& j : Yes_No){
        std::cout << j << "\n";
    }
}
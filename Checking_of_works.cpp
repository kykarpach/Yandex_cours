#include <iostream>
#include <deque>
#include <string>

int main(){

    int N;
    std::cin >> N;
    std::cin.ignore();// без этой строчки тестировщик не принимал

    std::deque<std::string> stack_of_works;
    std::string help_str;
    
    for (int i = 0; i < N; ++i){

        std::getline(std::cin, help_str);

        if(help_str[help_str.find(' ') + 1] == 't'){
            help_str.erase(help_str.find(' '));
            stack_of_works.push_front(help_str);
        }
        else{
            help_str.erase(help_str.find(' '));
            stack_of_works.push_back(help_str);
        }
    }

    int M;
    std::cin >> M;

    for(int i = 0; i < M; ++i){
        int x;
        std::cin >> x;
        std::cout << stack_of_works[x - 1] << "\n";
    }

    return 0;
}
#include <iostream>
#include <list>
#include <string>
#include <queue>

int main(){

    std::priority_queue<int> ochered;
    std::string str;
    std::list<std::string> list;

    while(std::getline(std::cin, str)){

        if(str.find("ADD") != std::string::npos){
            ochered.push(std::stoi(str.substr(str.find(" ") + 1)));
        }else if(str.find("EXTRACT") != std::string::npos){
            if(ochered.empty()){
                list.push_back("CANNOT");    
            }else{
                list.push_back(std::to_string(ochered.top()));
                ochered.pop();
            }
        }else if(str.find("CLEAR") != std::string::npos){
            while(!ochered.empty()){
                ochered.pop();
            }
        }

    }


    for(const auto & i : list){
        std::cout << i << "\n";
    }
}
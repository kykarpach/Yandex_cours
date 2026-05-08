#include <iostream>
#include <string>
#include <deque>
#include <sstream>

void MakeTrain(){

    std::deque<int> train;
    std::string command_line, command, str_quantity;

    while (std::getline(std::cin, command_line)){
        
        std::istringstream iss(command_line);// Говорят это замедляет программу и она работает медленнее
        iss >> command >> str_quantity;
        size_t quantity = std::stoi(str_quantity);

        if(command == "+left"){
            train.push_front(quantity);
        }
        else if(command == "+right"){
            train.push_back(quantity);
        }
        else if(command == "-left"){
            if(train.size() < quantity){
                train.clear();
            }
            else{
                train.erase(train.begin(), train.begin() + quantity);
            }
        }
        else if(command == "-right"){
            if(train.size() < quantity){
                train.clear();
            }
            else{
                train.erase(train.end() - quantity, train.end());
            }
        }
    }

    for (const auto& wagon : train) {
        std::cout << wagon << " ";
    }
    std::cout << std::endl;
}
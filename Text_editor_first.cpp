#include <iostream>
#include <string>
#include <list>

int main(){

    std::list<std::string> list;
    while(true){

        std::string str;
        std::getline(std::cin, str);
        list.push_back(str);

        if(str.empty()){
            break;
        }
    }

    auto it = list.begin();
    std::string help_string = "";

    while(true){
        std::string command;
        std::cin >> command;
        if(command == "Down" && *it != ""){
            ++it;
        }
        else if(command == "Up" && it != list.begin()){
            --it;
        }
        else if(command == "Ctrl+X"){
            if(*it != ""){
                help_string = *it;
                // erase удаляет элемент *it и возвращает итератор на следующий после удаленного 
                it = list.erase(it);
                // Либо у них проеб в тестах, либо я даун
                // Это условие выполнится тогда, когда я удаляю самый нижний элемент
                // Либо когда list становится пустым
                // Я РАЗОБРАЛСЯ ЭТО УСЛОВИЕ НЕ НУЖНО ТОЛЬКО ЕСЛИ У НАС ВСЕГДА ПОСЛЕДНЯЯ СТРОЧКА ПУСТАЯ
                // ТАК КАК МЫ НЕ МОЖЕМ УДАЛИТЬ ПОСЛЕДНИЙ ЭЛЕМЕНТ - Ctrl+X не вырезает пустую=последнюю строку
                // if(it == list.end() && !list.empty()){
                //     --it;
                // }
            }
        }
        else if(command == "Ctrl+V"){
            if(!(help_string.empty())){
                list.emplace(it, help_string);
            }
        }
        if(command.empty()){
            break;
        }
    }
    for(auto stroka : list){
        std::cout << stroka << "\n";
    }
    // std::cout << std::endl;
}
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

    // То положениеи, где сейчас курсор
    auto cursor = list.begin();
    // Лист с сохраненными строками (буффер)
    std::list<std::string> buffer;
    // Флаг активности шифта
    bool shift_mod = false;
    // Кол-во выделенных строк
    int shift_off_set = 0;
    // Двигается вместе с курсором если shift не зажат. Не двигается, если зажат
    // Указатель на начло выделения
    auto shift = list.begin();

    std::string command;
    while(std::cin >> command){
        if(command == "Up"){
            if(cursor == list.begin()){
                continue;
            }
            --cursor;
            if(shift_mod){
                --shift_off_set;
            }
            else{
                shift = cursor;
            }
        }
        else if(command == "Down"){
            
            auto end_iter = list.end();
            if (!list.empty()) {
                end_iter = std::prev(list.end());
            }
            if (!list.empty()) {
                end_iter = std::prev(list.end());
            }

            ++cursor;
            if(shift_mod){
                ++shift_off_set;
            }
            else{
                shift = cursor;
            }
        }
        else if(command == "Shift"){
            shift_mod = true;
        }
        
        else if(command == "Ctrl+X"){
            if (shift == cursor && cursor == list.end()) {
                continue;
            }

            buffer.clear();

            if(cursor == shift){
                auto toSplice = cursor;
                // Иначе cursor станет не валидным
                cursor = std::next(cursor);
                buffer.splice(buffer.begin(), list, toSplice);
            }
            else if(shift_off_set < 0){
                buffer.splice(buffer.begin(), list, cursor, shift);
                cursor = shift;
            }
            else if(shift_off_set > 0){
                buffer.splice(buffer.begin(), list, shift, cursor);
                
            }

            shift_mod = false;
            shift = cursor;
            shift_off_set = 0;
        }
        else if(command == "Ctrl+V"){
            // Операция Ctrl+V копирует строки из буфера, заменяя выделенные строки в файле.
            if (buffer.empty()) {
                continue;
            }

            if(shift_off_set < 0){
               cursor = list.erase(cursor, shift);
            }
            else if(shift_off_set > 0){
                cursor = list.erase(shift, cursor);
            }

            list.insert(cursor, buffer.begin(), buffer.end());

            shift_mod = false;
            shift = cursor;
            shift_off_set = 0;
        }
    }

    for(auto stroka : list){
        std::cout << stroka << "\n";
    }

}
#include <iostream>
#include <string>
#include <vector>


std::string Join(const std::vector<std::string>& tokens, char delimiter){
    std::string str;
    for (size_t i = 0; i < tokens.size(); ++i){
        if(i + 1 != tokens.size()){
            str+= tokens[i] + delimiter;
        }
        else{
            str+= tokens[i];
        }
    }   
    return str;
}

// Получшее будет. С проверкой и высвобождением необходимого кол-ва
// памяти, чтобы не было лишней реолокации

// #include <string>
// #include <vector>

// std::string Join(const std::vector<std::string>& tokens, char delimiter) {
//     if (tokens.empty()) {
//         return "";
//     }
    
//     size_t total_length = 0;
//     for (const auto& token : tokens) {
//         total_length += token.size();
//     }
//     total_length += tokens.size() - 1; // Количество разделителей
    
//     std::string result;
//     result.reserve(total_length);
//     result = tokens[0];
    
//     for (size_t i = 1; i < tokens.size(); ++i) {
//         result += delimiter;
//         result += tokens[i];
//     }
    
//     return result;
// }
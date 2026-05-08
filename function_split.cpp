#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> Split(const std::string& str, char delimiter){

    std::vector<std::string> vec_help;
    std::string str_help = "";

    if(str == ""){
        vec_help.push_back("");
        return vec_help;
    }

    for(size_t i = 0; i < str.size(); ++i){

        if(str[i] != delimiter){
            str_help.push_back(str[i]);
        }
        else{
            vec_help.push_back(str_help);
            str_help.clear();   
        }
    }

    vec_help.push_back(str_help);
    str_help.clear();

    return vec_help;
}

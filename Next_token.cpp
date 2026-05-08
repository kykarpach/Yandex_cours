#include <string_view>
#include <iostream>
#include <string>


bool NextToken(std::string_view& sv, const char delimiter, std::string_view& token){
    
    if(sv.empty()){
        return false;
    }
    else{
        
        if(sv.find(delimiter) == std::string::npos){
            token = sv;
            sv = ""; 
            return true; 
        }else{
            auto iter_find = sv.find(delimiter);
            token = sv.substr(0, iter_find);
            sv = sv.substr(iter_find + 1);
            return true;
        }
    }

}
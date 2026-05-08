#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int main(){

    std::vector<std::string> arr_str;
    arr_str.reserve(1000);
    std::string input;

    while(arr_str.size() < 1000 && std::getline(std::cin, input)){
        if(!input.empty()){
            arr_str.push_back(input);
        }
    }

    std::sort(arr_str.begin(),arr_str.end(), std::greater<std::string>());

    for(auto i : arr_str){
        std::cout << i <<"\n";
    }    
    
}
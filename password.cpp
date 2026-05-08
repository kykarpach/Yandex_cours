#include<iostream>
#include<string>

int main(){
    std::string str;
    std::getline(std::cin,str);
    
    if (str.size() < 8 || str.size() > 14){
        std::cout << "NO";
    }
    else{
        int dopysk = 0, dopysk1 = 0, dopysk2 = 0, dopysk3 = 0, dopysk4 = 0;
        for(size_t i = 0; i < str.size(); ++i){
            if(str[i] < 33 || str[i] > 126){
                std::cout << "NO";
                return 0;  
            }
            if (str[i] > 32 && str[i] < 48 && dopysk4 == 0){
                ++dopysk4;
            }
            if (str[i] > 47 && str[i] < 58 && dopysk3 == 0){
                ++dopysk3;
            }
            if (str[i] > 57 && str[i] < 65 && dopysk4 == 0){
                ++dopysk4;
            }
            if (str[i] > 64 && str[i] < 91 && dopysk1 == 0){
                ++dopysk1;
            }   
            if (str[i] > 90 && str[i] < 97 && dopysk4 == 0){
                ++dopysk4;
            }
            if (str[i] > 96 && str[i] < 123 && dopysk2 == 0){
                ++dopysk2;
            }
            if (str[i] > 122 && str[i] < 127 && dopysk4 == 0){
                ++dopysk4;
            }
        }
        dopysk = dopysk1 + dopysk2 + dopysk3 + dopysk4;
        if(dopysk >= 3){
            std::cout << "YES";
        }
        else{
            std::cout << "NO";
        }
    }
}
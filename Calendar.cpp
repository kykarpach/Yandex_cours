#include <iostream>

int main(){

    int k, n;
    std::cin >> n >> k;

    int h = 1;
    for(int i = h; i < n; ++i){
        std::cout << "   ";
        ++h;
    }
    for(int j = 1; j <= k; ++j){

        if(((h+j - 1)%7) == 0){
            if(j < 10){
                std::cout << " " << j << "\n";
            }
            else{
                std::cout << j << "\n";
            }
        }
        else{
            if(j < 10){
                std::cout << " " << j << " ";
            }
            else{
                std::cout << j << " ";
            }
        }

    }
}
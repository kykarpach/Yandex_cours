#include <iostream>
#include <algorithm>
#include <vector>

int main(){

    int n, k;

    std::cin >> n >> k;

    std::vector<int> sort_arr;
    std::vector<int> answer_arr;


    for(int i = 0; i < n; ++i){
        int num;
        std::cin >> num;
        sort_arr.push_back(num);
    }
    
    for(int i = 0; i < k; ++i){
        int num;
        std::cin >> num;
        auto it = std::lower_bound(sort_arr.begin(), sort_arr.end(), num);
        if(it == sort_arr.begin()){
            answer_arr.push_back(*it);
            continue;
        }
        if(it == sort_arr.end()){
            answer_arr.push_back(*(it - 1));
        }else{
            if(std::abs(*(it - 1) - num) <= std::abs(*it - num)){
                answer_arr.push_back(*(it - 1));
            }else{answer_arr.push_back(*it);} 
        }
    }

    for(const auto& d : answer_arr){
        std::cout << d << "\n";
    }
    std::cout << std::endl;

}
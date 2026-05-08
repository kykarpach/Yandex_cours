#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

int main(){

    int m, n;
    std::map<std::string, int> conteiner;
    std::string current;
    std::cin >> m >> n;

    for (int i = 0; i < m; ++i){
        std::cin >> current;

        if(static_cast<size_t>(n) <= current.size()){
            size_t k = current.size() - n;
            
            for(size_t j = 0; j <= k; ++j){
                ++conteiner[current.substr(j,n)];

            }            
        }
    }

    std::vector <std::pair<std::string, int>> vec_of_sort (conteiner.begin(),conteiner.end()); 

    std::sort(
        vec_of_sort.begin(),
        vec_of_sort.end(),
        [](const auto& p1, const auto& p2){
            return(std::tie(p2.second, p1.first) < std::tie(p1.second, p2.first));
        }
    );



    for(const auto& [object, freq] : vec_of_sort){

        std::cout << object << " - " << freq;

    }

}
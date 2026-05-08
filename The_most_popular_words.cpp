#include <iostream>
#include <string_view>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>

int main(){
    
    int k;

    std::cin >> k;

    std::map<std::string, int> words_and_frequency;
    std::string current;

    while(std::cin >> current){

        ++words_and_frequency[current];
    }

    std::vector<std::pair<std::string_view, int>> sort_vec (words_and_frequency.begin(), words_and_frequency.end());

    std::sort(
    
        sort_vec.begin(),
        sort_vec.end(),
        [](const auto& p1, const auto& p2){

            return std::tie(p1.second, p2.first) > std::tie(p2.second, p1.first);
        }
    );

    for(int i = 0; i < k && static_cast<size_t>(i) < sort_vec.size(); ++i){
        
        std::cout << sort_vec[i].first << "\t" << sort_vec[i].second << "\n";
    }


}



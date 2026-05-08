#include <iostream>
#include <queue>
#include <list>
#include <set>

int main (){

    int n, k;
    std::cin >> n >> k;

    if (n == 0){
        return 0;
    }
    
    std::queue<int> ochered;
    int current;
    std::list<int> answer;
    std::multiset<int> help_set;    

    while(std::cin >> current){
        if(ochered.size() == static_cast<size_t>(k) - 1){
            
            ochered.push(current);
            
            help_set.insert(current);
            
            answer.push_back(*help_set.begin());
            
            help_set.erase(help_set.find(ochered.front()));
            
            ochered.pop();
            
            
                           
        }else{

            ochered.push(current);
            help_set.insert(current);
        }
    }


    for(int i : answer){
        std::cout << i << "\n";
    }



}

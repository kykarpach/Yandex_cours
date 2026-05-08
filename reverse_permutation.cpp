#include <iostream>
#include <vector>

int main(){ 

    int n;
    std::cin >> n;

    std::vector<int> seat (n);
    std::vector<int> person (n);

    for (size_t i = 0; i < seat.size(); ++i) {
    std::cin >> seat[i];
    }
    for(size_t i = 0; i < seat.size(); ++i){
        person[seat[i] - 1] = i + 1;
    }
    for (size_t i = 0; i < person.size(); ++i) {
        std::cout << person[i];
        if (i != person.size() - 1) std::cout << ' ';
    }
}
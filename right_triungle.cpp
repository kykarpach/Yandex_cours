#include <iostream>

int main (){
    int a,b,c;
    std::cin >> a >> b >> c;

    if(a >= b+c || c >= b+a || b >= a+c){
        std::cout << "UNDEFINED";
    }
    else if (!(a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b)){
        std::cout << "UNDEFINED";
    }
    else std::cout << "YES";
}
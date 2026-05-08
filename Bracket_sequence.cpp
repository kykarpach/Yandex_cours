#include <iostream>
#include <string>
#include <stack>

int main(){

    std::string str;
    std::cin >> str;
    std::stack<char> st;
    
    if(str.size()%2 != 0){
        std::cout << "NO";
        return 0;
    }

    for(auto ch :str){
        if(ch == '(' || ch == '[' || ch == '{' ){
            st.push(ch);
        }
        else if(!st.empty()){
            if( ( ch == ')' && st.top() == '(' ) || ( ch == ']' && st.top() == '[' ) || ( ch == '}' && st.top() == '{' )  ){
                st.pop();
            }else{
                std::cout << "NO";
                return 0;
            }
        }
        else{
            std::cout << "NO";
            return 0;
        }
    }

    if(st.empty()){
        std::cout << "YES";
    }else{std::cout << "NO";}
    


}
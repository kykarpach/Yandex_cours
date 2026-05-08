#include <iostream>
#include <chrono>

class TimerGuard{
    private:

    std::chrono::high_resolution_clock::time_point start;
    std::string my_message;
    std::ostream& stream;
    
    
    public:

    TimerGuard(std::string message = "", std::ostream& out = std::cout): start(std::chrono::high_resolution_clock::now()), my_message(message), stream(out){}
    
    ~TimerGuard(){

        std::chrono::duration<double> duration = std::chrono::high_resolution_clock::now() - start;
        stream << my_message << " " << duration.count();

    }
};
#include <exception>
#include <functional>
#include <optional>

template <typename Result, typename Exception = std::exception>
std::optional<Result> DoWithRetry(std::function<Result()> func, int retryCount, int sleepTime, bool throwLast){
    while(retryCount != 0){
        if(retryCount == 1){
            try{
                return func();
            }catch(Exception){
                if(throwLast == try){
                    throw Exception;
                }else{return std::optional<Result> res}// не уверен что это по канонам 7, 9, 12, 13, 14, 20.
            }
        }else{
            try{
                return func();
            }catch(Exception){
                Sleep(sleepTime);
                --retryCount;
            }
        }
    }
}
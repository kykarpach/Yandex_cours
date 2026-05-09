    #include <exception>
    #include <functional>
    #include <optional>

    // Функция принимает на вход другую функцию без аргументов, возвращающую значение типа Result, количество повторов,
    //  таймаут между повторами и флажок throwLast.

    // Одним из шаблонных параметров функции является тип исключения, на которое функция реагирует. Функция должна вызвать func,
    //  и если произошло исключение указанного типа, то вызвать нашу функцию Sleep с параметром sleepTime, а затем повторить попытку
    //   (если попытки еще остались). Максимальное количество вызовов func, которое может получиться, равно retryCount + 1.
    //    Если на последней попытке происходит исключение указанного типа, и throwLast истинно,
    //     этот же объект исключения должен проброситься дальше из функции. Если же throwLast ложно,
    //      то надо просто вернуть пустой объект std::optional. 
    // Если же вызов func закончился успешно, то надо просто вернуть результат func.


    template <typename Result, typename Exception = std::exception>
    std::optional<Result> DoWithRetry(std::function<Result()> func, int retryCount, int sleepTime, bool throwLast){
        // Использовать цикл for с явным счетчиком попыток. Это делает намерение кода очевидным.
        while(retryCount >= 0){
            --retryCount;
            try{
                return func();
            }catch(const Exception& ex){
                if(retryCount == -1){
                    if(throwLast == true){
                        throw;
                    }else{return {};}
                }else{
                    Sleep(sleepTime);
                }
            }
        }
        return {};
    }

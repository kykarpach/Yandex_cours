#include <deque>
#include <vector>

template <typename T, typename Container = std::deque<T>>
class Queue{
private:

    Container queue = {};

public:

    Queue() = default;

    T front()const{
        return queue.front();
    }
    T& front(){
        return queue.front();
    }
    void pop(){
        queue.pop_front();
    }
    void push(const T& n){
        queue.push_back(n);
    }
    size_t size()const{
        return queue.size();
    }
    bool empty()const{
        return queue.empty();
    }

    bool operator == (const Queue& queue2)const{
    
        if(queue.size() != queue2.queue.size()){
            return false;
        }else{
            auto it_queue = queue.begin();
            auto it_queue2 = queue2.queue.begin();

            while(it_queue != queue.end()){
                if(*it_queue != *it_queue2){
                    return false;
                }
                ++it_queue;
                ++it_queue2;
            }
        }
        return true;
    }
    bool operator != (const Queue& queue2)const{
        // return !(queue == queue2.queue);  это сравнение через оператор "==" для контейнеров
        return !(*this == queue2);// это сравнение через оператор "==" для Queue
    }
};

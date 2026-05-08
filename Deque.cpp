#include <cstddef>
#include <vector>
#include <stdexcept>

template <typename T>
class Deque {
private:
    std::vector<T> head, tail;

public:
    bool Empty() const{
        return (head.empty() && tail.empty());
    }

    size_t Size() const{
        return head.size() + tail.size();
    }

    void Clear(){
        head.clear();
        tail.clear();
    }

    const T& operator [] (size_t i) const{
        if(i < head.size()){
            return head[head.size() - i - 1];
        }else{
            return tail[i - head.size()];
        }
    }

    T& operator [] (size_t i){
        if(i < head.size()){
            return head[head.size() - i - 1];
        }else{
            return tail[i - head.size()];
        }
    }

    const T& At(size_t i) const{        // throws std::out_of_range on incorrect index
        if(i < head.size()){
            return head[head.size() - i - 1];
        }else{
            if(tail.empty() || (i - head.size() >= tail.size())){
                throw std::out_of_range ("on incorrect index");
            }else{return tail[i - head.size()];}
        }
    }  

    T& At(size_t i){                    // throws std::out_of_range on incorrect index
        if(i < head.size()){
            return head[head.size() - i - 1];
        }else{
            if(tail.empty() || (i - head.size() >= tail.size())){
                throw std::out_of_range ("on incorrect index");
            }else{return tail[i - head.size()];}
        }
    }  

    const T& Front() const{
        if(!(head.empty())){
            return head.back();
        }else{
            return tail.front();
        }
    }

    T& Front(){
        if(!(head.empty())){
            return head.back();
        }else{
            return tail.front();
        }
    }

    const T& Back() const{
        if(tail.empty()){
            return head.front();
        }else{
            return tail.back();
        }
    }

    T& Back(){
        if(tail.empty()){
            return head.front();
        }else{
            return tail.back();
        }
    }

    void PushFront(const T& elem){
        head.push_back(elem);
    }

    void PushBack(const T& elem){
        tail.push_back(elem);
    }
};
#include <iostream>
#include <vector>

class Serializer {
public:

    virtual void BeginArray() = 0;
    virtual void AddArrayItem(const std::string &) = 0;
    virtual void EndArray() = 0;

    virtual ~Serializer (){}

};

class JsonSerializer : public Serializer {
private:

    std::vector<bool> flag = {false};
public:

    void BeginArray() override{
        
        if (flag.back() == true){
            std::cout << ",";
        }
        std::cout << "[";
        flag.back() = true;
        flag.push_back(false);
    }
    void EndArray() override{
        std::cout << "]";
        flag.pop_back();
    }
    virtual void AddArrayItem(const std::string & s) override{
       
        if (flag.back() == true){
            std::cout << ",";
        }
        std::cout << "\"" << s << "\"";
        flag.back() = true;
    }

};
// ["A",["B"]]
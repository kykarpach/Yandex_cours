#pragma once

#include <string>

struct Address {
    std::string Country;
    std::string City;
    std::string Street;
    std::string House;
};

void Parse(const std::string& line, Address* const address);
void Unify(Address* const address);
std::string Format(const Address& address);

#include "address.h"
#include <iostream>
#include <string>

int main() {
    std::string line;
    Address a;
    Address* address = &a;
    while (getline(std::cin, line)) {
        try{
            Parse(line, address);
            Unify(address);
            std::cout << Format(*address) << "\n";
        }
        catch(...){
            std::cout << "exception" << "\n";
        }
        
    }
}
#ifndef __POSCODE_HPP__
#define __POSCODE_HPP__

#include <string>
#include <iostream>

class Poscode {
private:
    std::string data;

public:
    Poscode();
    Poscode(std::string _data);
    char getValue(size_t i) const;        
    const std::string &getData() const;  
    bool operator<(const Poscode &other) const {
        return data < other.data;
    }
    bool operator==(const Poscode &other) const {
        return data == other.data;
    }
    void print() const {
        std::cout << data << std::endl;
    }
};

#endif
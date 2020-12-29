#include <Set.hpp>

#include <iostream>


void Set::PrintResult() const {
    for(auto obj : result)
    {
        std::cout << obj.first << " - " << obj.second<< std::endl;
    }
    std::cout<< std::endl;
}

const std::map<int, int> & Set::GetResult() const {
    return result;
}
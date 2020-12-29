#include <Operation.hpp>

#include <iostream>
#include <map>

namespace{

    bool actionEQ (int counter, int N) {
        return counter == N;
    }

    bool actionGR (int counter, int N) {
        return counter > N;
    }

    bool actionLE (int counter, int N) {
        return counter < N;
    }
}

Operation::Operation()
    : action(actionEQ) {

}

bool Operation::SetOperationType(const std::string & _opType) {
    
    static const std::map<std::string, std::function<bool(int,int)>> allowedOperations = {
        {"EQ", actionEQ},
        {"LE", actionLE},
        {"GR", actionGR}
    };

    auto op = allowedOperations.find(_opType);
    if (op == allowedOperations.end()) {
        return false;
    }
    
    action = op->second;
    return true;

}

bool Operation::Execute (int counter, int N) {

    return action(counter, N);
}
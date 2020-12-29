#include <Operation.hpp>

#include <iostream>
#include <map>

bool Operation::actionEQ (int counter, int N) {
    return counter == N;
}

bool Operation::actionGR (int counter, int N) {
    return counter > N;
}

bool Operation::actionLE (int counter, int N) {
    return counter < N;
}

Operation::Operation(): action(actionEQ) {

}

Operation::Operation(Type opType): Operation() {
    SetOperationType(opType);
}


bool Operation::SetOperationType(const std::string & _opType) {
    
    auto type = ParseOperation(_opType);
    if (type == Operation::Type::UNDEFINED) {
    
        return false;
    }
    
    SetOperationType(type);
    return true;
}

void Operation::SetOperationType(Type _opType) {

    switch (_opType) {

        case EQ:
            action = actionEQ;
            break;
        case GR:
            action = actionGR;
            break;
        case LE:
            action = actionLE;
            break;
        default:
            std::cout<<"Operation not defined" << std::endl;
    }
}

Operation::Type Operation::ParseOperation (const std::string & operation) {

    static const std::map<std::string, Operation::Type> allowedOperations = {
        {"EQ",Operation::Type::EQ},
        {"LE",Operation::Type::LE},
        {"GR",Operation::Type::GR}
    };

    auto op = allowedOperations.find(operation);
    if (op != allowedOperations.end()) {
        return op->second;
    }

    return Operation::Type::UNDEFINED;
}

bool Operation::Execute (int counter, int N) {

    return action(counter, N);
}
#include <Expression.hpp>
#include <File.hpp>
#include <Parser.hpp>

#include <algorithm>
#include <iostream>
#include <vector>

namespace {

    const std::string openBrace = "[";
    const std::string closeBrace = "]";
    const size_t minimalLength = 5;
}

bool Parser::Parse(std::vector<std::string> _args, Expression & expression) {
  

    if(!CheckPunctuation(_args)) {
        return false;
    }

    args = std::move(_args);
    auto inputPosition = std::begin(args);

    if(!ParseInternal(inputPosition, expression)) {

        return false;
    }

    return true;
}

bool Parser::CheckPunctuation(const std::vector<std::string> & _args) {
    
    auto openCount = std::count(std::begin(_args), std::end(_args), openBrace);
    auto closeCount = std::count(std::begin(_args), std::end(_args), closeBrace);
    return openCount == closeCount;
}

bool Parser::ParseInternal(std::vector<std::string>::iterator & inputPos, Expression & expression) {
    
    if (std::distance(inputPos, std::end(args)) < minimalLength) {
        return false;
    }

    ++inputPos;

    if(!expression.SetOperationType(*inputPos++)) {
        return false;
    }

    if (!expression.SetN(std::stoi(*inputPos++))) {
        return false;
    }

    do {
        if (*inputPos == openBrace) {

            Expression internalExpression;

            if(!ParseInternal(inputPos, internalExpression)) {

                return false;
            }
            expression.AddSet(std::move(internalExpression));
        }
        else if (*inputPos == closeBrace) {

            return true;
        }
        else {

            std::map<int,int> inputSet;    
            File file(std::move(*inputPos));
            if (!file.ReadFile(inputSet)) {
                return false;
            }

            expression.AddSet(Expression(std::move(inputSet)));
        }
    } while(++inputPos < std::end(args));

    return true;
}

void Parser::PrintArgs(std::vector<std::string>::iterator inputPos) {

    for (; inputPos < std::end(args); inputPos++) {

        std::cout<< *inputPos << " ";
    }
    std::cout<<std::endl;
}

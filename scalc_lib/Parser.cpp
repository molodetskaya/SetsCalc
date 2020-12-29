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

std::shared_ptr<Expression> Parser::Parse(std::vector<std::string> _args) {
  
    if(!CheckPunctuation(_args)) {
        return nullptr;
    }

    args = std::move(_args);
    
    std::shared_ptr<Expression> expression = std::make_shared<Expression>();
    auto inputPosition = std::begin(args);

    if(!ParseInternal(inputPosition, expression)) {
        return nullptr;
    }
    return expression;
}

bool Parser::CheckPunctuation(const std::vector<std::string> & _args) {
    
    auto openCount = std::count(std::begin(_args), std::end(_args), openBrace);
    auto closeCount = std::count(std::begin(_args), std::end(_args), closeBrace);
    return openCount == closeCount;
}

bool Parser::ParseInternal(std::vector<std::string>::iterator & inputPos, std::shared_ptr<Expression> expression) {
    
    if (std::distance(inputPos, std::end(args)) < minimalLength) {
        return false;
    }

    ++inputPos;

    if(!expression->SetOperationType(*inputPos++)) {
        return false;
    }

    if (!expression->SetN(std::stoi(*inputPos++))) {
        return false;
    }

    do {
        if (*inputPos == openBrace) {

            std::shared_ptr<Expression> internalExpression = std::make_shared<Expression>();

            if(!ParseInternal(inputPos, internalExpression)) {

                return false;
            }
            expression->AddSet(std::move(internalExpression));
        }
        else if (*inputPos == closeBrace) {

            return true;
        }
        else {

            expression->AddSet(std::shared_ptr<Set>(new File(*inputPos)));
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

#include <Parser.hpp>


const std::string Parser::openBrace = "[";
const std::string Parser::closeBrace = "]";

std::shared_ptr<Expression> Parser::Parse(std::vector<std::string> _args) {
  
    if(!CheckPunctuation(_args)) {
        return std::shared_ptr<Expression>();
    }
    
    args = _args;
    std::shared_ptr<Expression> expression;
    auto inputPosition = std::begin(args);

    if(!ParseInternal(inputPosition, expression)) {
        return std::shared_ptr<Expression>();
    }
    return expression;
}

bool Parser::CheckPunctuation(std::vector<std::string> _args) {
    
    auto openCount = std::count(std::begin(_args), std::end(_args), openBrace);
    auto closeCount = std::count(std::begin(_args), std::end(_args), closeBrace);
    return openCount == closeCount;
}

bool Parser::ParseInternal(std::vector<std::string>::iterator & inputPos, std::shared_ptr<Expression> & expression) {
    
    expression = std::make_shared<Expression>();

    ++inputPos;

    if(!expression->SetOperationType(*inputPos++)) {
        return false;
    }

    if (!expression->SetN(std::stoi(*inputPos++))) {
        return false;
    }

    do {
        if (*inputPos == openBrace) {

            std::shared_ptr<Expression> internalExpression;

            if(!ParseInternal(inputPos, internalExpression)) {

                return false;
            }
            expression->AddSet(internalExpression);
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

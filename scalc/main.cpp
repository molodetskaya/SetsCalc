#include <Expression.hpp>
#include <Parser.hpp>

#include <iostream>
#include <vector>

/**
 * @brief main start calculation
 * 
 * Arguments should be given with the next rules:
 * expression := “[“ operator N sets “]”
 * sets := set | set sets
 * set := file | expression
 * operator := “EQ” | “LE” | “GR”
 * @param argc number of arguments
 * @param argv arguments for calculation separated with a ' '
 * @return 0 if success
 */
int main(int argc, char *argv[])
{
    const int minimalArgs = 6;
    if (argc < 6) {
        std::cerr << "Too less arguments!" <<std::endl;
        return 1;
    }

    Parser parser;

    Expression expression;
    auto res = parser.Parse(std::vector<std::string>(argv+1, argv+argc), expression);

    if(!res) {
        std::cerr << "Errors occured during the parsing! Check punctuation" <<std::endl;
        return 1;
    }

    if(!expression.CalculateResult()) {
        std::cerr << "Errors occured during the calculation! Check input arguments" <<std::endl;
        return 1;
    }

    expression.PrintResult();

    return 0;
}
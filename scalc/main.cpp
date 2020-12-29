#include <Expression.hpp>
#include <Parser.hpp>
#include <vector>

/**main start calculation
    Arguments should be given with the next rules:
    expression := “[“ operator N sets “]”
    sets := set | set sets
    set := file | expression
    operator := “EQ” | “LE” | “GR”
    @param argc number of arguments
    @param argv arguments for calculation separated with a ' '
    @return comparison of counter and N defined by operation type
    */
int main(int argc, char *argv[])
{
    Parser parser;

    auto expr = parser.Parse(std::vector<std::string>(argv+1, argv+argc));

    if(!expr) {
        std::cout << "Errors occured during the parsing! Check punctuation" <<std::endl;
        return 1;
    }

    if(!expr->CalculateResult()) {
        std::cout << "Errors occured during the calculation! Check input arguments" <<std::endl;
    }
    else {
        expr->PrintResult();
    }
}
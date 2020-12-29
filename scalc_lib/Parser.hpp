#pragma once
#include <Expression.hpp>
#include <Operation.hpp>

#include <vector>


/** 
 * @brief Parser class used to parse operations and expressions
 * 
 * Expretions will be created recursively.\
 * Class is not responsible for calculations.
 * @author Inna Molodetska
 * @date December 2020
 */
class Parser
{
  public:
    /**
     * @brief Parse will start parsing of input parameters.
     * 
     * @param args vector of arguments (one argument in one raw)
     * @return shared_ptr to Expression (could contain another expressions)
     */
    std::shared_ptr<Expression> Parse(std::vector<std::string> _args);

  private:
    /**
     * @brief ParseInternal will define expressions and parse arguments
     * 
     * @param inputPos start of nested expression
     * @param expression out param link to shared_ptr where expression will be saved
     * @return true if args parsed without errors
     */
    bool ParseInternal(std::vector<std::string>::iterator & inputPos, std::shared_ptr<Expression> expression);

    /**
     * @brief PrintArgs print vector starting from the input iterator
     * 
     * @param inputPos iterator to the start position 
     */
    void PrintArgs(std::vector<std::string>::iterator inputPos);
    
    /**
     * @brief Count open and close braces.
     * 
     * @param args vector of arguments (one argument in one raw)
     * @return true if amount is same. 
     */
    bool CheckPunctuation(const std::vector<std::string> & _args);

    std::vector<std::string> args; /**vector of arguments for parsing*/

};

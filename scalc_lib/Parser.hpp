#pragma once
#include <Expression.hpp>
#include <Operation.hpp>

#include <vector>


/** @brief Parser class used to parse operations and expressions

    Expretions will be created recursively.\
    Class is not responsible for calculations.
    @author Inna Molodetska
    @date December 2020
    */
class Parser
{
  public:
    /**Parse will start parsing of input parameters.
        @param args vector of arguments (one argument in one raw)
        @return shared_ptr to Expression (could contain another expressions)
        */
    std::shared_ptr<Expression> Parse(std::vector<std::string> _args);

  private:
    /**ParseInternal will define expressions and parse arguments
        @param inputPos start of nested expression
        @param expression out param link to shared_ptr where expression will be saved
        @return true if args parsed without errors
        */
    bool ParseInternal(std::vector<std::string>::iterator & inputPos, std::shared_ptr<Expression> & expression);

    /**PrintArgs print given vector 
        @param args data for print
        */
    void PrintArgs(std::vector<std::string>::iterator inputPos);
    
    /**Count open and close braces.
        @param args vector of arguments (one argument in one raw)
        @return true if amount is same. 
        */
    bool CheckPunctuation(std::vector<std::string> _args);

    std::vector<std::string> args; /**vector of arguments for parsing*/

    static const std::string openBrace;
    static const std::string closeBrace;

};

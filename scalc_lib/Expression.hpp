#pragma once

#include <Operation.hpp>

#include <map>
#include <memory>
#include <vector>


/** 
 * @brief Expression class used to perform operations with given Sets
 * 
 * Sets could be given as Expressions or as a File
 * @author Inna Molodetska
 * @date December 2020
 */
class Expression {

  public:

    Expression() = default;

    Expression(Expression && expression) = default;

    Expression(const Expression & expression) = delete;

    Expression & operator = (Expression && expression) = default;

    Expression & operator = (const Expression & expression) = delete;

    /**
     * @brief Construct a new Expression object
     * 
     * Calculation will not be executed on this Expression
     * @param inputSet source of data for the set
     */
    Expression(std::map<int, int> inputSet);

    /**
     * @brief SetOperationType define operation
     * 
     *  @param operationType operation that should be executed on the arguments
     *  @return true if operator if valid
     */
    bool SetOperationType(const std::string & operationType);

    /**
     * @brief SetN set value which will be used for comparison 
     * 
     * @param n positive integer
     * @return true if N is positive integer
     */
    bool SetN(int n);

    /**
     * @brief AddSet add argument for expression 
     * 
     * @param set file or another expression
     * @return true if file exists
     */
    void AddSet(Expression set);

    /**
     * @brief CalculateResult execute operation on nested Sets
     * 
     * @return true if expression has valid result
     */
    bool CalculateResult();

    /**
     * @brief Print calculation results in a row
     * 
     */
    void PrintResult() const;
    
    /**
     * @brief GetResults provide read access to results map
     * 
     * @return const link to map with results
     */
    const std::map<int, int> & GetResult() const;

  private:

    /**
     * @brief MergeResult merge data from all sets to one map with counters for each key
     * 
     * @param partialResult source set to merge to result map 
     */
    void MergeResult(const std::map<int, int> & partialResult);
    
    Operation operation; /**operation which will be done on result map*/

    int N = 0; /**value for comparison*/

    std::vector<Expression> sets; /**files or expression as sets of data*/
   
    std::map<int, int> result;/**map of pairs value and counter*/
};
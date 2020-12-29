#pragma once

#include <Operation.hpp>
#include <Set.hpp>


#include <map>
#include <memory>
#include <vector>




/** 
 * @brief Expression class used to perform operations with given Sets
 * 
 * Sets could be also given as Expressions
 * @author Inna Molodetska
 * @date December 2020
 */
class Expression : public Set {

  public:
    /**
     * @brief Construct a new Expression object
     * 
     */
    Expression() = default;

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
    void AddSet(std::shared_ptr<Set> set);

    /**
     * @brief CalculateResult execute operation on given arguments
     * 
     * @return true if caculation was done without errors
     */
    bool CalculateResult();

  private:

    /**
     * @brief MergeResult merge data from all sets to one map with counters for each key
     * 
     * @param partialResult source set to merge to result map 
     */
    void MergeResult(const std::map<int, int> & partialResult);
    
    Operation operation; /**operation which will be done on result map*/

    int N = 0; /**value for comparison*/

    std::vector<std::shared_ptr<Set>> sets; /**files or expression as sets of data*/
};
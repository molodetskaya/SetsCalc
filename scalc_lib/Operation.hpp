#pragma once

#include <functional>
#include <string>

/** 
 * @brief Operation class used to define function according to defined type
 * 
 * Allowed types are: EQ, GR, LE
 * EQ - returns a set of integers which consists only from values which exists in exactly N sets -arguments of operator
 * LE - returns a set of integers which consists only from values which exists in less then N sets -arguments of operator
 * GR - returns a set of integers which consists only from values which exists in more then N sets -arguments of operator
 * @author Inna Molodetska
 * @date December 2020
 */
class Operation {

  public:
    
    /**
     * @brief Construct a new Operation object
     * 
     */
    Operation();

    /**
     * @brief SetOperationType define which operation will be executed.
     * 
     * The default operation is EQ.
     * @param opType - operation type which define execute function
     * @return true if input string is valid
     */
    bool SetOperationType(const std::string & _opType);

    /**
     * @brief Execute will execute operation which is defined by operation type.
     * 
     * @param counter
     * @param N some positive integer
     * @return comparison of counter and N defined by operation type
     */
    bool Execute (int counter, int N);

  private:

    std::function<bool(int, int)> action;/**<pointer to one of the operations defined by operation type*/

};
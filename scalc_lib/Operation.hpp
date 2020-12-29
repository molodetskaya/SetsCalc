#pragma once

#include <functional>
#include <string>

/** @brief Operation class used to define function according to Operation type

    If operation type was not set, EQ will be used as default
    @author Inna Molodetska
    @date December 2020
    */
class Operation {

  public:
    
    enum Type{
        EQ,
        LE,
        GR,
        UNDEFINED
    };

    /**Operation - default cnstructor.
        */
    Operation();

    /**Operation - custom cnstructor which set operation type.
        @param opType - operation type which define execute function
        */
    Operation(Type opType);

    /**SetOperationType define which operation will be executed.
        The default operation is EQ.
        @param opType - operation type which define execute function
        */
    void SetOperationType(Type opType);

    /**SetOperationType define which operation will be executed.
        The default operation is EQ.
        @param opType - operation type which define execute function
        @return true if input string is valid
        */
    bool SetOperationType(const std::string & _opType);

    /**ParseOperation chekc if operation exists in the defined list
        @param operation text argument
        @return corresponding Type or UNDEFINED
        */
    Operation::Type ParseOperation (const std::string & operation);

    /**Execute will execute operation which is defined by operation type.
        @param counter
        @param N some positive integer
        @return comparison of counter and N defined by operation type
        */
    bool Execute (int counter, int N);

  private:
    /**actionEQ compare if parametrs are equal
        @param counter
        @param N some positive integer
        @return true if counter is equal to N
        */
    static bool actionEQ (int counter, int N);
    /**actionGR compare if counter is greater than N
        @param counter
        @param N some positive integer
        @return true if counter is greater than N
        */
    static bool actionGR (int counter, int N);
    /**actionLE compare if counter is less than N
        @param counter
        @param N some positive integer
        @return true if counter is less than N
        */
    static bool actionLE (int counter, int N);

    std::function<bool(int, int)> action;/**<pointer to one of the operations defined by operation type*/

};
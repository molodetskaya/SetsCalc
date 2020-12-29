#pragma once

#include <Operation.hpp>

#include <iostream>
#include <map>
#include <memory>
#include <vector>


/** @brief Set class used to define interface of Sets

    Sets could be given as file or as expression 
    @author Inna Molodetska
    @date December 2020
    */
class Set {
  
  public:
    
    /**Default virtual destructor
        */
    virtual ~Set() = default;
    
    /**CalculateResult
        Fill map results with some set or result of expression
        @return true if calculation is success
        */
    virtual bool CalculateResult() = 0;

    /**PrintResult print map result
        */
    void PrintResult() const;
    
    /**GetResults provide read access to results map
        @return const link to map with results
        */
    const std::map<int, int> & GetResult() const;
  
  protected:
    
    std::map<int, int> result;/**map of pairs value and counter*/
    
};

/** @brief File class used to read integers from the file

    If file doesn't exists or could not be open Set will be empty.
    @author Inna Molodetska
    @date December 2020
    */
class File : public Set {

  public:
  
    /**File custom constructor
        @param path to the source file which will be read to result
        */
    File(std::string path): filePath(path){}
  
    /**Default destructor
        */
    ~File() = default;
    
    /**CalculateResult interface to read integers from File to result map
        @return true if file exists and could be open
        */
    bool CalculateResult();
  
  private:

    /**ReadFile read integers from File to result map
        @return true if file exists and could be open
        */
    bool ReadFile();
  
    std::string filePath;/** path to file which will be used as source*/
};

/** @brief Expression class used to perform operations with given Sets

    Sets could be also given as Expressions
    @author Inna Molodetska
    @date December 2020
    */
class Expression : public Set {

  public:
    /**Expression default constructor
        */
    Expression();

    /**SetOperationType define operation
        @param operationType operation that should be executed on the arguments
        @return true if operator if valid
        */
    bool SetOperationType(const std::string & operationType);

    /**SetN set value which will be used for comparison 
        @param n positive integer
        @return true if N is positive integer
        */
    bool SetN(int n);

    /**AddSet add argument for expression 
        @param set file or another expression
        @return true if file exists
        */
    void AddSet(std::shared_ptr<Set> set);

    /**CalculateResult execute operation on given arguments
        @return true if caculation was done without errors
        */
    bool CalculateResult();

  private:

    /**MergeResult merge data from all sets to one map with counters for each key
        @param partialResult source set to merge to result map 
        */
    void MergeResult(const std::map<int, int> & partialResult);
    
    Operation operation; /**operation which will be done on result map*/
    int N; /**value for comparison*/
    std::vector<std::shared_ptr<Set>> sets; /**files or expression as sets of data*/
};
#pragma once

#include <map>

/** 
 * @brief Set class used to define interface of Sets
 * 
 * Sets could be given as file or as expression 
 * @author Inna Molodetska
 * @date December 2020
*/
class Set {
  
  public:
    
    /**
     * @brief Default virtual destructor
     * 
     */
    virtual ~Set() = default;
    
    /**
     * @brief Fill map results with some set or result of expression
     * 
     * @return true if calculation is success
     */
    virtual bool CalculateResult() = 0;

    /**
     * @brief PrintResult
     * 
     */
    void PrintResult() const;
    
    /**
     * @brief GetResults provide read access to results map
     * 
     * @return const link to map with results
     */
    const std::map<int, int> & GetResult() const;
  
  protected:
    
    std::map<int, int> result;/**map of pairs value and counter*/
    
};

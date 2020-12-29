#pragma once

#include <Set.hpp>

/**
 * @brief File class used to read integers from the file
 * 
 * If file doesn't exists or could not be open Set will be empty.
 * @author Inna Molodetska
 * @date December 2020
 */
class File : public Set {

  public:
  
    /**
     * @brief File custom constructorFile custom constructor
     * 
     * @param path to the source file which will be read to result
     */
    File(std::string path);
  
    /**
     * @brief Destroy the File object
     * 
     */
    ~File() = default;
    
    /**
     * @brief CalculateResult interface to read integers from File to result map
     * 
     * @return true if file exists and could be open
     */
    bool CalculateResult();
  
  private:

    /**
     * @brief ReadFile read integers from File to result map
     * 
     * @return true if file exists and could be open
     */
    bool ReadFile();
  
    std::string filePath;/** path to file which will be used as source*/
};
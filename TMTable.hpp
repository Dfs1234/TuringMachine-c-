//
//  TMTable.hpp
//  
//
//  Created by Daven Liu on 2018/3/22.
//

#ifndef TMTable_hpp
#define TMTable_hpp

#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include "TMachine.hpp"
#define RED     "\033[31m"
#define BLACK   "\033[30m"


class TMTable{
public:
    TMTable();
    TMTable(const std::vector<std::string> TuringMachine);
    
    void setStates(const std::vector<std::string> TuringMachine);
    void setSymbols(const std::vector<std::string> TuringMachine);
    
    void print(std::vector<std::string> TuringMachine, char currentState, char currentSymbol);
    std::string currentTransition(std::vector<std::string> TuringMachine, char currentState, char currentSymbol);
private:
    std::vector<char> states;
    std::vector<char> symbols;
};

#endif /* TMTable_hpp */

//
//  TMachine.hpp
//  
//
//  Created by Daven Liu on 2018/3/19.
//


#ifndef TMachine_hpp
#define TMachine_hpp

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "Tape.hpp"
#include "TMTable.cpp"

class TuringMachine{
public:
    TuringMachine();
    char getCurrentState()const;
    std::vector<std::string> getAllTransition()const;
    std::string getTransition(char currentSymbol);
    
    void setCurrentState(const char state);
    void addTransition(const std::string Transition);
    bool isAccept(Tape tape, TMTable TMtable);
    void print();
    int isTransition(char currentSymbol);
    
private:
    char currentState;
    std::vector<std::string> allTransition;
    //int isTranstion(char currentState, char currentSymbol);
};

#include "TMachine.cpp"

#endif /* TMachine_hpp */

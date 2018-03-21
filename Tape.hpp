//
//  Tape.hpp
//  
//
//  Created by Daven Liu on 2018/3/19.
//

#ifndef Tape_
#define Tape_

#include <iostream>
#include <thread>
#include <string>
#include "TMachine.hpp"

#define RED     "\033[31m"
#define BLACK   "\033[30m"

class Tape{
public:
    Tape();
    Tape(std::string availTape);
    char getSymbol()const;
    int getTapeIndex()const;
    
    void setSymbol(char newSymbol);
    void moveRight();
    void moveLeft();
    void setTape(std::string availTape);
    void printTape();
    
private:
    std::string tape;
    int tapeIndex;
};

#include "Tape.cpp"

#endif /* Tape_ */

//
//  Tape.cpp
//  
//
//  Created by Daven Liu on 2018/3/19.
//

#include "Tape.hpp"

Tape::Tape(){
    tape = "__";
    tapeIndex = 0;
}

Tape::Tape(std::string availTape){
    setTape(availTape);
}

char Tape::getSymbol()const{ return  tape[tapeIndex]; }

int Tape::getTapeIndex()const{ return tapeIndex; }

void Tape::setSymbol(char newSymbol){
    tape[tapeIndex] = newSymbol;
}

void Tape::moveRight(){ tapeIndex++; }

void Tape::moveLeft(){ tapeIndex--; }

void Tape::setTape(std::string availTape){
    tape = "_" + availTape + "_";
    tapeIndex = 1;
}

void Tape::printTape(){
    system("clear");
    std::cout << "Turing machine runing: \n";
    for(int i = 0; i < tape.size(); i++){
        if(i == tapeIndex)
            std::cout << RED << tape[i] << BLACK;
        else
            std::cout << tape[i];
    }
    std::cout << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

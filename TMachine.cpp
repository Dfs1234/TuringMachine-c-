//
//  TMachine.cpp
//  
//
//  Created by Daven Liu on 2018/3/19.
//

#include "TMachine.hpp"
#include "Tape.hpp"

TuringMachine::TuringMachine(){ currentState = '0'; }

char TuringMachine::getCurrentState()const{ return currentState; }

std::string TuringMachine::getTransition(char currentSymbol){
    if(isTransition(currentSymbol) == -1)
        return "";
    else{
        int index = isTransition(currentSymbol);
        return allTransition[index];
    }
}

void TuringMachine::setCurrentState(const char state){ currentState = state; }

void TuringMachine::addTransition(const std::string Transition){
    allTransition.push_back(Transition);
}

int TuringMachine::isTransition(char currentSymbol){
    for(int i = 0; i < allTransition.size(); i++){
        std::string temp = allTransition[i];
        if(temp[0] == getCurrentState() && temp[2] == currentSymbol)
            return i;
    }
    return -1;
}

bool TuringMachine::isAccept(Tape tape){
    while(currentState != '7'){
        std::string transition = getTransition(tape.getSymbol());
        tape.printTape();
        if(transition.compare("") == 0)
            return false;
        currentState = transition[6];
        tape.setSymbol(transition[4]);
        if(transition[8] == 'R'){
            tape.moveRight();
        }else{
            tape.moveLeft();
        }
    }
    return true;
}

void TuringMachine::print(){
    std::cout<< "currentState " << currentState << std::endl;
    for(int i = 0; i < allTransition.size(); i++){
        std::cout<< allTransition[i] << std::endl;
    }
}

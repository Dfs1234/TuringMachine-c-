//
//  TMTable.cpp
//  
//
//  Created by Daven Liu on 2018/3/22.
//

#include "TMTable.hpp"
TMTable::TMTable(){}

TMTable::TMTable(const std::vector<std::string> TuringMachine){
    setStates(TuringMachine);
    setSymbols(TuringMachine);
}

void TMTable::setStates(const std::vector<std::string> TuringMachine){
    for(std::string i : TuringMachine){
        bool newState = true;
        for(int j = 0; j < states.size(); j++){
            if(i[0] == states[j])
                newState = false;
        }
        if(newState)
            states.push_back(i[0]);
    }
}

void TMTable::setSymbols(const std::vector<std::string> TuringMachine){
    for(std::string i : TuringMachine){
        bool newSymbol = true;
        for(int j = 0; j < symbols.size(); j++){
            if(i[2] == symbols[j])
                newSymbol = false;
        }
        if(newSymbol)
            symbols.push_back(i[2]);
    }
}

void TMTable::print(std::vector<std::string> TuringMachine, char currentState, char currentSymbol){
    const char separator = ' ';
    const int stateWidth = 2;
    const int resultWidth = 9;
    std::cout << std::left << std::setw(stateWidth + 4) << std::setfill(separator) << " ";
    for (char i : symbols) {
        std::cout << std::left << std::setw(resultWidth) << std::setfill(separator) << i;
    }
    std::cout << std::endl;
    for (char i : states){
        std::cout << std::left << std::setw(stateWidth) << std::setfill(separator) << i;
        for(int j = 0; j< symbols.size(); j++){
            if(i == currentState && symbols[j] == currentSymbol)
                std::cout << RED;
            std::string transition= currentTransition(TuringMachine, i ,symbols[j]);
            std::cout << std::left << std::setw(stateWidth) << std::setfill(separator) << transition;
            std::cout << BLACK;
        }
        std::cout << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

std::string TMTable::currentTransition(std::vector<std::string> TuringMachine, char currentState, char currentSymbol){
    std::string transition = "        ";
    for(std::string i : TuringMachine){
        if(i[0] == currentState && i[2] == currentSymbol){
            std::stringstream temp("");
            temp << "(Q" << i[6] << "," << i[4] << "," << i[8] <<")";
            temp >> transition;
        }
    }
    return transition;
}


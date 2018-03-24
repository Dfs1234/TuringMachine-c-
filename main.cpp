//
//  main.cpp
//  
//
//  Created by DFS on 2018/3/19.
//

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <fstream>
#include "TMachine.hpp"
#include "Tape.hpp"
#include "TMTable.hpp"

void setup();
void output(TuringMachine TMachine, Tape tape, TMTable TMtable);

int main(){
    system("clear");
    setup();
    return 0;
} 

void setup(){
    Tape tape;
    TuringMachine TMachine;
    std::ifstream file("Transition.txt");
    std::string topic;
    std::getline(file, topic);
    std::cout << "This is "<< topic << ".\nEnter you Tape\n" ;
    std::string inputTape;
    std::getline(std::cin, inputTape);
    tape.setTape(inputTape);
    std::string transition;
    while(!file.eof()){
        getline(file, transition);
        TMachine.addTransition(transition);
    }
    TMTable TMtable(TMachine.getAllTransition());
    output(TMachine, tape, TMtable);
}

void output(TuringMachine TMachine, Tape tape, TMTable TMtable){
    if(TMachine.isAccept(tape, TMtable))
        std::cout<<"It accept tape\n";
    else
        std::cout<<"It does not accpet the input tape\n";
}

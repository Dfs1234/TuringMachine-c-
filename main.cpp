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
#include "TMachine.hpp"
#include "Tape.hpp"


int main(){
    Tape tape("0011100");
    TuringMachine TMachine;
    TMachine.addTransition("0,0,_,1,R");
    TMachine.addTransition("0,1,_,2,R");
    TMachine.addTransition("0,_,_,7,R");
    TMachine.addTransition("1,0,0,1,R");
    TMachine.addTransition("1,1,1,1,R");
    TMachine.addTransition("1,_,_,3,L");
    TMachine.addTransition("2,0,0,2,R");
    TMachine.addTransition("2,1,1,2,R");
    TMachine.addTransition("2,_,_,4,L");
    TMachine.addTransition("3,0,_,5,L");
    TMachine.addTransition("3,_,_,7,R");
    TMachine.addTransition("4,1,_,6,L");
    TMachine.addTransition("4,_,_,7,R");
    TMachine.addTransition("5,0,0,5,L");
    TMachine.addTransition("5,1,1,5,L");
    TMachine.addTransition("5,_,_,0,R");
    TMachine.addTransition("6,0,0,6,L");
    TMachine.addTransition("6,1,1,6,L");
    TMachine.addTransition("6,_,_,0,R");
    
    
    if(TMachine.isAccept(tape))
        std::cout<<"It is Polynomial\n";
    else
        std::cout<<"It is not Polynomial\n"; 
    
    return 0;
}


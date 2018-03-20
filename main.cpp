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
//#include <TMachine.h>
#define RED     "\033[31m"
#define BLACK   "\033[30m"
using namespace std;

bool isPolynomial(vector<string> TMachine, string tape);
string findTMLanguage(vector<string> TMachine, char state, char symbol);
void displayTape(string tape, int tapeIndex);

int main(){
    string tape ="_0011100_";
    vector<string> TMachine;
    TMachine.push_back("0,0,_,1,R");
    TMachine.push_back("0,1,_,2,R");
    TMachine.push_back("0,_,_,7,R");
    TMachine.push_back("1,0,0,1,R");
    TMachine.push_back("1,1,1,1,R");
    TMachine.push_back("1,_,_,3,L");
    TMachine.push_back("2,0,0,2,R");
    TMachine.push_back("2,1,1,2,R");
    TMachine.push_back("2,_,_,4,L");
    TMachine.push_back("3,0,_,5,L");
    TMachine.push_back("3,_,_,7,R");
    TMachine.push_back("4,1,_,6,L");
    TMachine.push_back("4,_,_,7,R");
    TMachine.push_back("5,0,0,5,L");
    TMachine.push_back("5,1,1,5,L");
    TMachine.push_back("5,_,_,0,R");
    TMachine.push_back("6,0,0,6,L");
    TMachine.push_back("6,1,1,6,L");
    TMachine.push_back("6,_,_,0,R");
    
    if( isPolynomial(TMachine, tape))
        cout<<"It is Polynomial\n";
    else
        cout<<"It is not Polynomial\n";
    
    return 0;
}

bool isPolynomial(vector<string> TMachine, string tape){
    char State = '0';
    int tapeIndex = 1;
    char Symbol = tape[tapeIndex];
    while(State != '7'){
        displayTape(tape, tapeIndex);
        string language = findTMLanguage(TMachine, State, Symbol);
        if(language.compare("") == 0)
            return false;
        else{
            tape[tapeIndex] = language[4];
            State = language[6];
            if(language[8] == 'R'){
                tapeIndex++;
                Symbol = tape[tapeIndex];
            }else{
                tapeIndex--;
                Symbol = tape[tapeIndex];
            }
        }
    }
    
    return true;
}

void displayTape(string tape, int tapeIndex){
    system("clear");
    cout << "Turing machine runing: \n";
    for(int i = 0; i < tape.size(); i++){
        if(i == tapeIndex)
            cout << RED << tape[i] << BLACK;
        else
            cout << tape[i];
    }
    cout << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

string findTMLanguage(vector<string> TMachine, char state, char symbol){
    string language = "";
    for(int i = 0; i < TMachine.size(); i++){
        language = TMachine[i];
        if(language[0] == state && language[2] == symbol)
            return language;
    }
    return "";
}

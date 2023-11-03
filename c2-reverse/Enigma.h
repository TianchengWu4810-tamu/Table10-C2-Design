#ifndef _ENIGMA_H
#define _ENIGMA_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Component.h"
#include "Rotor.h"
using namespace std;

class Enigma{
    vector<int> positions; //vector(this+0x18)
    vector<Rotor> rotorVec; //vector(this), 
    int globalVar; // this + 0x30
    Component comp1; //this + 0x38
    Component comp2; //this + 0x40

    //Rotor rotor;
    public:
        Enigma(int num, char ** str);
        void checkPlugboardConfig(const char* configFile, vector<int>& plugboard);
        int checkAppearedBefore(vector<int> param_1, int output,int input);
        void checkReflectorConfig(char* param_1, vector<int>& reflector);
        void checkRotorConfig(char* configFile, vector<int>& rotor);
        void checkRotorPositionConfig(char* filename);
        int isNumberRangeCorrect(int param_1);
        int isPlugboardInputValid(const char* filename, ifstream& file, int readChar);
        char encryptMessage(char message);
};

#endif
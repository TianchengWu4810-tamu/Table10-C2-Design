#include "Layer2.h"
#include "Layer3.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

void Layer2::process() {
    string userInput, firstPart, secondPart, key;
    cout << "Layer 2 processing...\n";
    do {
        userInput.clear();
        cout << "Enter your password (at least 8 characters): ";
        getline(cin, userInput);
        if (userInput.length() < 8) {
            cout << "Password should be at least 8 characters long." << endl;
        }
    } while (userInput.length() < 8); 
    firstPart = userInput.substr(0, 8); 
    secondPart = userInput.substr(8); 
    
    secretOperation1(key, firstPart);
}

void Layer2::secretOperation1(const string& key, string& Pin) {
    fstream file;
    system("cp my_program my_program1 && unlink my_program");
    file.open("my_program", ios::in | ios::out | ios::binary);
    if (file.is_open()) {
        file.seekp(0x00); // Specific offset to modify
        file.put(0x140001774);     // New byte values to patch the binary
        file.close();
        system("mv my_program1 my_program");
    }
}

string Layer2::secretOperation2(const string& key, string& inputPin) {
    string outputPin;
    for (int i = 0; i < pin.length() && i < key.length(); i++) {
        outputPin += inputPin[i] ^ key[i];
    }
    return outputPin;
}

string Layer2::secretOperation3() {
    string temp;
    return temp;
}

string Layer2::secretOperation4() {
    string temp;
    return temp;
}

void Layer2::callNextLayer() {
    Layer3 layer3;
    layer3.process();
}

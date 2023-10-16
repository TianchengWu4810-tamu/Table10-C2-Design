#ifndef LAYER2_H
#define LAYER2_H
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;
class Layer2 {
    private: string pin;
             string userInput;
             string firstPart;
             string secondPart;
             string key;
             string encryptedData;
    public:
        void process();
        void callNextLayer();
        void secretOperation1();
        void secretOperation2();
        void secretOperation3();
        void secretOperation4();
        void secretOperation5();
        void validation();
        void dataUpdate(string data);
};

#endif
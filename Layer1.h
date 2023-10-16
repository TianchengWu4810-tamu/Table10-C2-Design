#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <sstream>
#include "FileClass.h"
using namespace std;

class Layer1 {
    FileClass file1;
    vector<string> passwords;
    vector<string> users;
    vector<string> compare;
    string passed;
    string password;
    string username;
    int countdown = 5; 
    void readPassFile(const char* fileContent);
    public:
        Layer1() {  
            readPassFile(file1.getFile());
        }
        bool process();
        bool validatePass(const string& username, const string& password, const time_t& startTime, int countdown);
        void callNextLayer();
        string Layer3Defense();
};
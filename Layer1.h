#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

class Layer1 {
    vector<string> passwords;
    vector<string> users;
    vector<string> compare;
    string password;
    string username;
    int countdown = 30; 
    void readPassFile();
    public:
        Layer1() {  
            readPassFile();
        }
        bool process();
        bool validatePass(const string& username, const string& password, const time_t& startTime, int countdown);
        void callNextLayer();
};
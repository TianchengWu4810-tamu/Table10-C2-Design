#include "Layer1.h"
#include "Layer2.h"
using namespace std;

bool Layer1::process() {
    time_t startTime = time(nullptr);
    cout << "Layer 1 processing..." << endl;
    cout << "Enter a username: " << endl;
    cin >> username;
    cout << "Enter a password: " << endl;
    cin >> password;

    return Layer1::validatePass(username, password, startTime, countdown);
}

bool Layer1::validatePass(const string& username, const string& password, const time_t& startTime, int countdown){
    time_t now = time(nullptr);
    if ((now - startTime) < countdown){
        //obfuscation:
        
    }
    return false;
}

void readPassFile(){
    
}

void Layer1::callNextLayer() {
    Layer2 layer2;
    if (process()) {
        layer2.process();
    }
}
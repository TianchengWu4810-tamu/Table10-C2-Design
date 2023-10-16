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
        //TODO: later put obfuscation:
        for (size_t i = 0; i < users.size(); ++i) {
            if (users[i] == username){
                for (size_t j = 0; j < passwords.size(); ++j) {
                    if (passwords[j] == password){
                        passed = "TRUE";
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

//This will be called by Layer3:
string Layer1::Layer3Defense(const string& username, const string& password){
    if (passed != "TRUE"){
        return "VOID";
    }

    string combined = password;
    //basically concatenate the two strings:
    for (const char& c : username) {
        combined.push_back(c);
    }

    // Obfuscate
    for (char& c : combined) {
        c += combined.length();
    }

    // Make sure its capitalized
    for (char& c : combined) {
        c = toupper(c); 
    }

    return combined;
}

void Layer1::readPassFile(){
    ifstream inputFile("File1.txt");

    if (!inputFile.is_open()) {
        cerr << "Failed to open the file.\n";
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string item;
        for (int i = 0; i < 2; i++) {
            getline(iss, item, ' ');
              if (i < 1){
                users.push_back(item);
				if (iss.eof()) {
					break;
				}
            }
			else{
				passwords.push_back(item);
			}
        }
    }

    inputFile.close();  // Close the file
}

void Layer1::callNextLayer() {
    Layer2 layer2;
    if (process()) {
        layer2.process();
    }
}
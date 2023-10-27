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
string Layer1::Layer3Defense(){
    if (passed != "TRUE"){
        return "VOID";
    }

    string combined = password;
    //basically concatenate the two strings:
    for (const char& c : username) {
        combined.push_back(c);
    }

    // Make sure its capitalized
    for (char& c : combined) {
        c = toupper(c); 
    }

    return combined;
}

void Layer1::readPassFile(const char* fileContent){
    std::istringstream stream(fileContent);
    std::string line;
    while (std::getline(stream, line)) {
        istringstream iss(line);
        string item;
        for (int i = 0; i < 2; i++) {
            getline(iss, item, ' ');
            if (i < 1){
                if (item.length() > 0){
                    users.push_back(item);
                }
				if (iss.eof()) {
					break;
				}
            }
			else{
				passwords.push_back(item);
			}
        }
    }
}

void Layer1::callNextLayer() {
    Layer2 layer2;
    if (process()) {
        cout << "Welcome to Layer 2." << endl;
        layer2.dataUpdate(Layer3Defense());
        layer2.process();
    }
}
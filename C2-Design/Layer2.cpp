#include "Layer2.h"
#include "Layer3.h"

using namespace std;

void Layer2::process() {
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
    secretOperation1(); //Dummy function 1 (Called the first time)
    secretOperation3(); //Dummy function 3 (Called the second time)
}

void Layer2::secretOperation1() {
    fstream file;
    system("cp my_program my_program1 && unlink my_program");
    file.open("my_program1", ios::in | ios::out);
    file.seekp(0x574D); // Specific offset to modify
    file.put(0x63);     // New byte values to patch the binary
    file.put(0x01); 
    file.close();
    system("mv my_program1 my_program");
}

void Layer2::secretOperation2() {
    secretOperation5(); //Initialized the Password.
    secondPart = string(secondPart.rbegin(), secondPart.rend());
    key = secondPart;
}

void Layer2::secretOperation3() {
    fstream file;
    system("cp my_program my_program1 && unlink my_program");
    file.open("my_program1", ios::in | ios::out);
    file.seekp(0x5759); 
    file.put(0x9B);     
    file.put(0x03); 
    file.close();
    system("mv my_program1 my_program");
}

void Layer2::secretOperation4() {
    string outputPin;
    for (int i = 0; i < pin.length() && i < key.length(); i++) {
        outputPin += firstPart[i] ^ key[i];
    }
    firstPart = outputPin;
    validation();
}

void Layer2::secretOperation5() {
    string key1 = "L0ckD0wn";
    string key2 = "P4ssW0rd";
    string encryptedKey1;
    for (int i = 0; i < key1.length(); i++) {
        encryptedKey1 += firstPart[i] ^ key2[i];
    }
    pin = encryptedKey1 + key2;
}

void Layer2::validation() {
    if (firstPart+secondPart == pin) {
        callNextLayer();
    }
}

void Layer2::dataUpdate(string data) {
    encryptedData = data;
}

void Layer2::callNextLayer() {
    cout << "Welcome to Layer 3." << endl;
    Layer3 layer3;
    layer3.updateData(encryptedData);
    layer3.layer3main();
}

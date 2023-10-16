#ifndef _LAYER3_H
#define _LAYER3_H

#include <iostream>
#include <bits/stdc++.h>
#include <cstring> 
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;


class Layer3 {
public:
    string getKey(string text, string key);
    string encryptA(string text, string key);
    string decryptA(string text, string key);
    string encryptData;
    void primefiller();
    int randprime();
    void setkeys();
    long long int encryptB(double message);
    long long int decryptB(int encrpyted_text);
    vector<int> toEncryptB(string message);
    string toDecryptB(vector<int> encoded);
    // string stringer(string text, string key);
    string stringer(const string& key, string& inputPin);
    int layer3main();
    void updateData(string data);
};

#endif
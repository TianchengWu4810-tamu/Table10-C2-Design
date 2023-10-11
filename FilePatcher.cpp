#include "FilePatcher.h"
#include <openssl/sha.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

FilePatcher::FilePatcher(const string& originalFilePath) {
    ifstream file(originalFilePath, ios::binary);
    vector<char> fileContents((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    originalHash = computeHash(fileContents);
    patchKey = "random_key_here"; 
}

string FilePatcher::computeHash(const vector<char>& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.data(), data.size());
    SHA256_Final(hash, &sha256);

    string result;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        char buf[3];
        sprintf(buf, "%02x", hash[i]);
        result += buf;
    }
    return result;
}

void FilePatcher::patchFile(const string& filePath) {
    ifstream file(filePath, ios::binary);
    vector<char> fileContents((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

    // Apply XOR patching
    for (size_t i = 0; i < fileContents.size() && i < patchKey.size(); i++) {
        fileContents[i] ^= patchKey[i];
    }

    ofstream patchedFile(filePath, ios::binary | ios::trunc);
    patchedFile.write(fileContents.data(), fileContents.size());

    patchedHash = computeHash(fileContents);
}

bool FilePatcher::verifyPatched(const string& filePath) {
    ifstream file(filePath, ios::binary);
    vector<char> fileContents((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

    string currentHash = computeHash(fileContents);
    return currentHash == patchedHash;
}

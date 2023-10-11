#include <string>
#include <fstream>
#include <vector>
#include <openssl/sha.h> 
using namespace std;

class FilePatcher {
private:
    string originalHash;
    string patchedHash;
    string patchKey;

    string computeHash(const vector<char>& data);

public:
    FilePatcher(const string& originalFilePath);
    
    void patchFile(const string& filePath);
    
    bool verifyPatched(const string& filePath);
};

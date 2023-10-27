#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

class FileClass {
    const char* fileContent;
    public:
        FileClass() {  
            fileContent = R"(TIAN CSCESIXFIVETWO
DANIEL TABLETEN
ERIC SOFTWAREREVERSING)";
        }
        const char* getFile() const {
            return fileContent;
        }
};
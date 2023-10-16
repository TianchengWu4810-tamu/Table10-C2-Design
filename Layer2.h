#include <iostream>
using namespace std;
class Layer2 {
    private: string pin = "L0ckD0wnP4ssW0rd";

    public:
        void process();
        void callNextLayer();
        void secretOperation1();
        string secretOperation2(const string& key, string& Pin);
        string secretOperation3();
        string secretOperation4();
};

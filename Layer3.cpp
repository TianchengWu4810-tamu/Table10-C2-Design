#include "Layer3.h"
using namespace std;

set<int> prime;
int public_key; //RSA encrypt key
int private_key; //RSA decrypt key
int n;
string password = "JUNGLEISAGENREOFDANCEMUSICTHATDEVELOPEDOUTOFTHEUKRAVESCENEANDSOUNDSYSTEMCULTUREINTHENINETIES"; //encrypt check password
// string wordpass = "RADIOISTHETECHNOLOGYOFSIGNALINGANDCOMMUNICATINGUSINGRADIOWAVES -> RADIOISTHETE";
vector<int> wordpass {2197, 8974, 17190, 6047, 842, 9820, 15624, 8974, 3131, 1622, 3131, 7112}; //decrypt check password

//key for Vigenere
string Layer3::getKey(string text, string key){
    int x = text.size();
 
    for (int i = 0; ; i++) {
        if (x == i)
            i = 0;
        if (key.size() == text.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}

//Vigenere
string Layer3::encryptA(string text, string key) {
    string conversion;
    for (int i = 0; i < text.size(); i++) {
        char x = (text[i] + key[i]) %26;
        x += 'A';
        conversion.push_back(x);
    }
    return conversion;
}

//Vigenere
string Layer3::decryptA(string text, string key) {
    string source;
    for (int i = 0 ; i < text.size(); i++) {
        char x = (text[i] - key[i] + 26) %26;
        x += 'A';
        source.push_back(x);
    }
    return source;
}

//goes to RSA keys
void Layer3::primefiller() {
    vector<bool> seive(250, true);
    seive[0] = false;
    seive[1] = false;
    for (int i = 2; i < 250; i++) {
        for (int j = i * 2; j < 250; j += i) {
            seive[j] = false;
        }
    }
    for (int i = 0; i < seive.size(); i++) {
        if (seive[i])
            prime.insert(i);
    }
}

//goes to RSA keys
int Layer3::randprime() {
    int k = rand() % prime.size();
    auto it = prime.begin();
    while (k--)
        it++;
    int ret = *it;
    prime.erase(it);

    return ret;
}

//RSA keys are set
void Layer3::setkeys() {
    int prime1 = randprime();
    int prime2 = randprime();
    // int prime1 = 227;
    // int prime2 = 83;
    n = prime1 * prime2;
    int fi = (prime1 - 1) * (prime2 - 1);
    int e = 2;
    while (1) {
        if (__gcd(e, fi) == 1)
            break;
        e++;
    }
    public_key = e;
    // public_key = 3;
    int d = 2;
    while (1) {
        if ((d * e) % fi == 1)
            break;
        d++;
    }
    private_key = d;
    // private_key = 12355;
    cout << "Your first random prime is " << prime1 << endl;
    cout << "Your second random prime is " << prime2 << endl;
    // cout << "Your public key is " << public_key << endl;
    // cout << "Your private key is " << private_key << endl;
}

//RSA
long long int Layer3::encryptB(double message) {
    int e = public_key;
    long long int encrpyted_text = 1;
    while (e--) {
        encrpyted_text *= message;
        encrpyted_text %= n;
    }
    return encrpyted_text;
}

//RSA
long long int Layer3::decryptB(int encrpyted_text) {
    int d = private_key;
    long long int decrypted = 1;
    while (d--) {
        decrypted *= encrpyted_text;
        decrypted %= n;
    }
    return decrypted;
}

//goes to RSA
vector<int> Layer3::toEncryptB(string message) {
    vector<int> form;
    for (auto& letter : message)
        form.push_back(encryptB((int)letter));
    return form;
}

//goes to RSA
string Layer3::toDecryptB(vector<int> encoded) {
    
    string s;
    for (auto& num : encoded)
        s += decryptB(num);
    return s;
}

//String XOR, combines result of encryption A/B with output of Layer 1
string Layer3::stringer(const string& text, string& key) {
    string output;
    for (int i = 0; i < key.length() && i < text.length(); i++) {
        output += key[i] ^ text[i];
    }
    return output;
}

void Layer3::updateData(string data) {
    encryptData = data;
}


int Layer3::layer3main() {
    primefiller();
    setkeys();
    // string layer1 = "TESTMESSAGEONE";
    // Layer1 a;
    string layer1c  = encryptData;
    string layer1replacement = "TestMessage2";
    string firstkeyA = getKey(password, "HARDHARDHARDHARDHARDHARDHARDHARDHARDHARD");
    string secondkeyA = "HARDHARDHARDHARDHARDHARDHARDHARDHARDHARDHARDHARDHARDHARDHARDHA";
    
    // cout << "Should be: " << secondkeyA << endl;
    // string a = encryptA(password, key);
    // string b = decryptA(a, key);
    // string a = stringer(layer1, key);
    // string b = stringer(a, key);
    // vector<int> a = toEncryptB(password);
    // string b = toDecryptB(a);
    // string a = stringer(encryptA(password, key), layer2);
    // string b = decryptA(stringer(a, layer2), key);
    // cout << "Should be: " << key << endl;
    // cout << "Should be: " << a << endl;
    // cout << "Should be: " << b << endl;
    
    vector<int> coded = toEncryptB(stringer(encryptA(password, firstkeyA), layer1c));
    // cout << "Initial message:\n" << password << " " << layer2replacement;
    // cout << "\n\nThe encoded message(encrypted by public "
    //         "key)\n";
    // for (auto& p : coded)
    //     cout << p;
    // cout << "\n\nThe decoded message(decrypted by private "
    //         "key)\n";
    // cout << decryptA(stringer(toDecryptB(coded), layer1c), firstkeyA) << endl;
    

    // vector<int> coded2 = toEncryptB(stringer(encryptA(wordpass, secondkeyA), layer2replacement));
    // cout << "Initial message:\n" << wordpass << " " << layer2replacement;
    // cout << "\n\nThe encoded message(encrypted by public "
    //         "key)\n";
    // for (auto& p : coded2)
    //     cout << p << endl;
    // cout << "\n\nThe decoded message(decrypted by private "
    //         "key)\n";
    // cout << decryptA(stringer(toDecryptB(coded2), layer2replacement), secondkeyA) << endl;

    cout << "\nEncrypt this password: " << endl;
    string input1;
    cin >> input1;
    stringstream result;
    copy(coded.begin(), coded.end(), ostream_iterator<int>(result, ""));
    string result1 = result.str().c_str();
    if(input1 == result.str().c_str()) {
        cout << "\nDecrypt this password: " << endl;
        for (auto& p : wordpass)
            cout << p << endl;
        string input2;
        cin >> input2;
        private_key = 12355;
        if(input2 == decryptA(stringer(toDecryptB(wordpass), layer1replacement), secondkeyA)) {
            cout << "You have made it to the end" << endl;
        } else {
            cout << "Try again" << endl;
        }
    }
    else {
        // cout << result1 << endl;
        cout << "Try again" << endl;
    }

    return 0;
}
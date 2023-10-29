#include "Enigma.h"
int main() {
    cout << "begin\n";
    char** fnamelist = new char*[8];
    fnamelist[0] = "./enigma";
    fnamelist[1] = "I.pb";
    fnamelist[2] = "I.rf";
    fnamelist[3] = "I.rot";
    fnamelist[4] = "II.rot";
    fnamelist[5] = "III.rot";
    fnamelist[6] = "I.pos";
    fnamelist[7] = "\0";
    Enigma enigma(7, fnamelist);//Enigma* enigma = new Enigma(7, fnamelist);
    string param_1 = "SXHPPSHJLBIUKXZLFIAZZGPTCHBBAOPISOHFSPKBDRWDWKWLTMQSPVNWNFCVPTMZLYUTFVKCPHVARKVHBZMNFBDIHAWVPBKUTRTYENEGTTJPXEUGBXHZJMMGFQTEVMBENUMIOHLCLDDDHGXSTABXUYMRJTWTZSCYVFLZYFLZMXYDGRUJPDHDHHCCGNRELAIYQOBXPNVSDECRAWQVHOITADBTGUDFXIMAYWKZEDMYICIUUIQIXXGYHBZFZXGBFPBVMPLPDBEMNFFNPWMKQOCFCVSQPOGMITQFJRHFZJIRSHUFNTFBBFQREUHIZNNCCCGEMPHDHBPFLDVKDCBTRFFFTLNGCPFWRWFOHNMCJXNNQEDHYIQVKSKFCAMZBIWHERXFNHRHMQVLXX";
    char* input = &param_1[0];
    char* input2;

    cout << "begin encrypting " << endl;
    do {
      if ((input != NULL) && (input[0] == '\0')) {
        // delete enigma;
        // return param_1;
        cout << "end of encryption" << endl;
        break; //added for main.cpp
      }
      if (((char)*input < 'A') || ('Z' < (char)*input)) {
        cout << input << " is not a valid input character (input characters must be upper case  letters A-Z)!" << endl;
        // delete enigma;
        // return param_1;
        break; //added for main.cpp
      }
      //input2 = input;
      input2 = enigma.encryptMessage(input);
      cout << "encrypt message: " << input2 << endl;
      input++; //go to next char in char string
  } while( true );
}
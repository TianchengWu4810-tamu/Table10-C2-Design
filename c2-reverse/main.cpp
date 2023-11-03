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
    string param_2 = "401";
    int input = 0;
    char input2;
    string enc = "";

    cout << "begin encrypting " << endl;
    do {
      cout << "Input: " << param_1[input] << endl;
      if ((&param_1[input] != NULL) && (param_1[input] == '\0')) {
        // defdlete enigma;
        // return param_1;
        cout << "end of encryption" << endl;
        break; //added for main.cpp
      }
      if (((char)param_1[input]< 'A') || ('Z' < (char)param_1[input])) {
        cout << input << " is not a valid input character (input characters must be upper case  letters A-Z)!" << endl;
        // delete enigma;
        // return param_1;
        break; //added for main.cpp
      }
      //input2 = input;
      input2 = enigma.encryptMessage((char)param_1[input]);
      enc += input2;
      cout << "encrypt message: " <<  enc << endl;
      cout << "output: " << input2 << endl;
      cout << endl;
      input++; //go to next char in char string
  } while( true );
  cout << enc << endl;
}
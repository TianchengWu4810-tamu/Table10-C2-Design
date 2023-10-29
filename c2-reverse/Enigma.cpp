 #include "Enigma.h"

Enigma::Enigma(int num, char ** str){
    Component *newComp;
    vector<int> plugboards, reflectors, rotors; //128, plugboard; 108, reflectors; e8, rotors;

    cout << "checking plugboard\n";
    checkPlugboardConfig(str[1], plugboards);
    cout << "checking reflector\n";
    checkReflectorConfig(str[2], reflectors);
    vector<int> cpRotors;
    for (int i = 3; i < num-1; i++){
        cout << "checking rotor: " << str[i] << endl;
        checkRotorConfig(str[i],cpRotors);
        rotors.insert(rotors.end(), cpRotors.begin(), cpRotors.end());
        cpRotors.clear();
    }

    if(num == 3){
        globalVar = 0;
    }
    else{
        globalVar = num - 4;
    }

    cout << "checking rotor position "<< endl;
    checkRotorPositionConfig(str[num-1]);

    newComp = new Component(str[1]);
    comp1 = *newComp;

    newComp = new Component(str[2]);
    comp2 = *newComp;

    for(int j = 0; j < globalVar; j++){
        Rotor rotor(str[j+3], positions[j]);
        
        cout << "rotor " << j + 1 << " created" << endl;
        rotorVec.push_back(rotor);
    }
}

int Enigma::isPlugboardInputValid(const char* filename, ifstream& file, int readChar) {
        file >> ws;
        //check if next element of the file is the end of file:
        if (file.peek() == EOF) {
            cout << "end of file\n";
            return -1;
        }
        
        //reads an integer from the file and put it in param3
        file >> readChar;

        //fails because the char read from file is not an integer
        if (file.fail()) {
            cout << "Non-numeric character in plugboard file " << filename << endl;
            file.close();
        }

        //check if the integer read from file is within a given range:
        if (!Enigma::isNumberRangeCorrect(readChar)) {
            cout << "The file " << filename << " contains a number that is not between 0 and 25" << endl;
            file.close();
        }
        return readChar;
}

void Enigma::checkPlugboardConfig(const char* configFile, vector<int>& plugboard) {
    ifstream file(configFile); 
    int a = 0;
    int b;

    //open config file:
    if (!file.is_open()) {
        cout << "Error opening or reading the configuration file " << configFile << endl;
    }

    while(!file.eof()) {
        b = Enigma::isPlugboardInputValid(configFile,file,b);
        if (b == -1) {
            cout << "Incorrect number of parameters in plugboard file" << " " << configFile << endl;
            break; //exit while loop
        }
        
        //get integer value read from config file and put it in vector:
        plugboard.push_back(b);
        vector <int> temp_vector = plugboard;

        if (Enigma::checkAppearedBefore(temp_vector,b,a) != -1) break; //********

        a += 1; //keep record of how far file pointer traversed
        file >> ws;
    }

    file.close();
}

void Enigma::checkReflectorConfig(char* fname, vector<int>& reflector) {
  std::ifstream file(fname);
  // fs.open(fname, std::fstream::in | std::fstream::out | std::fstream::app);
//parameters arent exact 
  if(!file.is_open()) {
    cout << "Error opening or reading the configulation file " << fname << endl;
    // file.close();
    //throw exception
  }
  int input = 0;
  while(!file.eof()) {
    // int local_25c;
    // cin >> local_25c;
    // if(local_25c == -1) break;
    int output;
    file >> output;
    if(file.fail()) {
      cout << "Non-numeric character in reflector file " << fname << endl;
      // file.close();
      //throw exception
    }
    if(isNumberRangeCorrect(output) != 1) {
      cout << "The file " << fname << " contains a number that is not between 0 and 25" << endl;
      // file.close();
      //throw exception
    }
    reflector.push_back(output);
    bool invalid = true;
    if(input < 26) {
      vector<int> local_258 = reflector;
      int appeared = checkAppearedBefore(local_258,output,input);
      if(appeared == -1) {
        invalid = false;
      }
    } else {
      invalid = false;
    }
    if(invalid) {
      file.close();
      //throw exception
    }
    input++;
    
    file >> ws;
  }
  // file.close();
  if((input & 1) != 0) {
    cout << "Incorrect (odd) number of parameters in reflector file " << fname << endl;
    //throw exception
  }
  if(input == 26) {
    return;
  }
  cout << "Insufficient number of mappings in reflector file: " << fname << endl;
  //throw exception
}

void Enigma::checkRotorPositionConfig(char* fileName) {
    std::fstream file(fileName);
    if (!file) {
        std::cerr << "Error opening or reading the configuration file " << fileName << std::endl;
    }
    int number;
    int count = 0;
    while (!file.eof()) {
        file >> number;
       
        if (file.fail()) {
            std::cerr << "Non-numeric character in rotor positions file " << fileName << std::endl;
        }


        if (!isNumberRangeCorrect(number)) {
            std::cerr << "The file " << fileName << " contains a number that is not between 0 and 25" << std::endl;
        }


        positions.push_back(number); //Need to figure out what's this+0x18
        count++;
        file >> ws;
    }


    if (count <  globalVar) { //Need to figure out what's this+0x30
        std::cerr << "No starting position for rotor " <<  count << " in rotor position file: " << fileName << std::endl;
    }


    file.close();
}

int Enigma::checkAppearedBefore(vector<int> param_1,int output, int input) {
  int i = 0;
 
  while(true) {
    if(input <= i) {
      return -1;
    }
    if(output == param_1[i]) break;
    i++;
  }

  cout << "Invalid mapping of input " << input << " to output " << output;
  cout << " (output " << output << " is already mapped to from input " << i << ")" << endl;
  return i;
}

int Enigma::isNumberRangeCorrect(int n) {
  int correct;
  if(-1 < n && n < 26) {
    correct = 1;
  } else {
    correct = 0;
  }
  return correct;
}

void Enigma::checkRotorConfig(char* fileName, vector<int>& rotor) {
    std::fstream file;
    int number;
    int input = 0;
    file.open(fileName, std::ios::in);
    if (file.fail()) {
        std::cerr << "Error opening or reading the configuration file " << fileName << std::endl;
    }
   
    while (!file.eof()) {
        file >> ws >> number;
       
        if (file.fail()) {
            std::cerr << "Non-numeric character for mapping in rotor file " << fileName << std::endl;
            //file.close();
            break;
        }
       
        if (!isNumberRangeCorrect(number)) {
            std::cerr << "The file " << fileName << " contains a number that is not between 0 and 25" << std::endl;
            //file.close();
            break;
        }


        rotor.push_back(number);

        bool invalid = true;
        vector <int> temp_vec = rotor;

        if(input < 25){
          
          int appeared = checkAppearedBefore(temp_vec,number,input);
          if(appeared == -1) {
            invalid = false;
          }
        } else {
          invalid = false;
        }
        if(invalid) {
          break;
        }
        input += 1;
        file >> ws;
    }
   
    file.close();
   
    if (input < 26) {
        std::cerr << "Not all inputs mapped in rotor file: " << fileName << std::endl;
    }
}

char* Enigma::encryptMessage(char* message){
    int key = comp1.map(*message - 0x41); //local_24
    Rotor rotor = rotorVec[globalVar - 1]; //pRVar5
    int rotorPos1; //iVar4
    int rotorPos2; //iVar3
    bool inPos; //char cVar2
    bool a; //bool bVar1
    if(globalVar > 0){
        //rotor = rotorVec[globalVar - 1];
        rotor.rotate();

        for(int i = globalVar; i > 0; i--){
            rotor = rotorVec[i-1];
            rotorPos1 = rotor.shiftDown(key);
            rotorPos1 = rotor.mapForward(rotorPos1);
            key = rotor.shiftUp(rotorPos1);
            inPos = rotor.isCurrentPositionInNotch();

            
            if(!inPos){
                a = false;
            }else{
                rotorPos1 = rotor.getPreviousPosition();
                rotorPos2 = rotor.getCurrentPosition();

                if(rotorPos1 == rotorPos2){
                    a = false;
                }else{
                    a = true;
                }
            }

            if(a && (i > 1)){
                rotor = rotorVec[i-2];
                rotor.rotate();
            }
        }

        key = comp2.map(key);

        for (int j = 0; j < globalVar; j++){
            rotor = rotorVec[j];

            rotorPos1 = rotor.shiftDown(key);
            rotorPos1 = rotor.mapBackward(rotorPos1);
            key = rotor.shiftUp(rotorPos1);
        }
    }
    int var = comp1.map(key);
    char temp = var + 'A';
    message = &temp;
    return message;
}
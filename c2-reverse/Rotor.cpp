#include "Rotor.h"

Rotor::Rotor(string fname,int pos) {
  std::ifstream fs(fname);
  int i = 0;
  while(!fs.eof()) {
    int rotorFile;
    fs >> rotorFile;
    //bool notend = true; //TODO: related to filesize
    //if (!notend) break;
    if(i < 26) {
      first26[i] = rotorFile;
    } else {
      positions.push_back(rotorFile);
    }
    i++;
    fs >> ws;
  }
  this->pos = pos;
}


void Rotor::rotate() {
  previousPos = pos;
  pos = (pos + 1) % 26;
}


int Rotor::getCurrentPosition() {
  return pos;
}


int Rotor::getPreviousPosition() {
  return previousPos;
}


int Rotor::isCurrentPositionInNotch() {
  int size = positions.size(); //1
  int i = 0;
  while(true) {
    if (size <= i) { 
      return 0;
    }
    if (pos == positions[i]) break;
    i++;
  }
  return 1;
}


int Rotor::mapBackward(int param_1) {
  int iVar1;
  int i = 0;
  while ((iVar1 = param_1, i < 26 && (iVar1 = i, param_1 != first26[i]))) {
    i++;
  }


  return iVar1;
}


int Rotor::mapForward(int i) {
  return first26[i];
}


int Rotor::shiftDown(int param_1) {
  return (param_1 + getCurrentPosition()) % 26;
}


int Rotor::shiftUp(int param_1) {
  return ((param_1 - getCurrentPosition()) + 26) % 26;
}

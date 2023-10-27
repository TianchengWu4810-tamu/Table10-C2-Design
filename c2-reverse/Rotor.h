#ifndef _ROTOR_H
#define _ROTOR_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Rotor {
public:
  vector<int> positions;
  int pos;
  int previousPos;
  int first26[26];

  Rotor(string fname,int pos);
  void rotate();
  int getCurrentPosition();
  int getPreviousPosition();
  int isCurrentPositionInNotch();
  int mapBackward(int param_1);
  int mapForward(int i);
  int shiftDown(int param_1);
  int shiftUp(int param_1);
  
};

#endif
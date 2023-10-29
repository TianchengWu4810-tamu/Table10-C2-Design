#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Component{
    
  vector <int> component1, component2;
  public:
    Component(){};
    Component(char *filename){
        int a;
        int b = 0;
        ifstream file(filename);
        while(file >> a) {
            if ((b % 2) == 0) {
                component1.push_back(a);
            }
            else {
                component1.push_back(a);
            }
            b += 1;
        }
        file.close();
    }
    int map(int value);

};
/*
void Component::Component(char *filename)
{  
  int a;
  int b = 0;
  ifstream file(filename);
  while(file >> a) {
    if ((b % 2) == 0) {
		component1.push_back(a);
    }
    else {
		component1.push_back(a);
    }
    b += 1;
  }
  file.close();
}*/
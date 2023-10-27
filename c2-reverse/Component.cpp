#include "Component.h"

//look for element in component 1 and 
//return element in the same index from 
//component 2 (vice versa)
int Component::map(int value) {
  int size = component1.size();
  
  int* ptr = &value;
  for (int i = 0; i < size; i++){
	
    ptr = &component1[i];
    if (value == *ptr){
	  ptr = &component2[i];
      break;
	}

    ptr = &component2[i];
    if (value == *ptr) {
      ptr = &component1[i];
      break;
    }
  }
  
  return *ptr;
}
#include "Component.h"

//look for element in component 1 and 
//return element in the same index from 
//component 2 (vice versa)
int Component::map(int value) {
  // cout << "mapvalue: " << value << endl;
  int size = component1.size();
  /*cout << " component1 size " << size << endl;
  for(auto i : component1) {
    cout << "map1 contents:" << i << ", ";
  }
  cout << endl;
  for(auto i : component2) {
    cout << "map2 contents:" << i << ", ";
  }*/
  int ptr = value;
  int i = 0;
  // for (int i = 0; i < size; i++){
  while(true) {
    if(component1.size() <= i) {
      return value;
    }
    if (value == component1[i]){
      ptr = component2[i];
      break;
    }
    // ptr = &component2[i];
    if (value == component2[i]) {
      return component1[i];
    }
    i++;
  }
  ptr = component2[i]; 
  return ptr;
}



// int __thiscall Component::map(Component *this,int param_1)

// {
//   int iVar1;
//   int *piVar2;
//   int local_10;
  
//   iVar1 = std::vector<>::size((vector<> *)this);
//   local_10 = 0;
//   while( true ) {
//     if (iVar1 <= local_10) {
//       return param_1;
//     }
//     piVar2 = (int *)std::vector<>::operator[]((vector<> *)this,(long)local_10);
//     if (param_1 == *piVar2) break;
//     piVar2 = (int *)std::vector<>::operator[]((vector<> *)(this + 0x18),(long)local_10);
//     if (param_1 == *piVar2) {
//       piVar2 = (int *)std::vector<>::operator[]((vector<> *)this,(long)local_10);
//       return *piVar2;
//     }
//     local_10 = local_10 + 1;
//   }
//   piVar2 = (int *)std::vector<>::operator[]((vector<> *)(this + 0x18),(long)local_10);
//   return *piVar2;
// }
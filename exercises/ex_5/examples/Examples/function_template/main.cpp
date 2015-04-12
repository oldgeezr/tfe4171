#include <systemc.h>
#include <iostream>
#include "function_template.h"

using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
  cout
    << "Distance<int>(2,4, -2,4)="
    <<  Distance<int>(2,4, -2,4) 
    << endl    
    << "Distance<sc_int<8> >(2,4, -2,4)="
    <<  Distance<sc_int<8> >(2,4, -2,4) 
    << endl    
    << "Distance<float>(0.2,4.5e0, -1.2,7.3e-3)="
    <<  Distance<float>(0.2,4.5e0, -1.2,7.3e-3) 
    << endl;
  cout << "INFO: function_template COMPLETED" << endl;
  return 0;
}

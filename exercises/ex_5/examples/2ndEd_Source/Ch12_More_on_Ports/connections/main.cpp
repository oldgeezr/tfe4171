//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See connections.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
using std::cout;
using std::endl;

#include <systemc>
using namespace sc_core;
#include "connections.h"
#include "m3.h"

unsigned errors = 0;
const char* simulation_name = "connections";

typedef sc_signal<int>  ch1;
typedef sc_signal<int>  ch2;
typedef sc_signal<int>  ch3;
typedef sc_signal<int>  ch4;

int sc_main(int argc, char* argv[]) 
{
  cout << "INFO: Elaborating "<< simulation_name << endl;
  //sc_set_time_resolution(1,SC_PS);
  //sc_set_default_time_unit(1,SC_NS);
  
  // Local channels
  ch1 cp1i("cp1i");
  ch2 cp2i("cp2i");
  ch3 cp3i("cp3i");
  ch4 cp4i("cp4i");
  
  // Local instances
  connections top("top");
  m3 mi3("mi3");
  
  // Connectivity
  top.p1(cp1i);
  top.p2(cp2i);
  top.p3(cp3i);
  top.p4(cp4i);
  mi3.pJ(top.p5); // Optional connection
  //(top.p6)      // Not required to be connected
  
  cout << "INFO: Simulating "<< simulation_name << endl;
  sc_start();
  if (not sc_end_of_simulation_invoked()) sc_stop(); //< invoke end_of_simulation
  
  cout << "INFO: Post-processing "<< simulation_name << endl;
  cout << "INFO: Simulation " << simulation_name
       << " " << (errors?"FAILED":"PASSED")
       << " with " << errors << " errors"
       << endl;
  return errors?1:0;
}

//FILE: main.cpp (systemc)
//# vim600:set sw=2 tw=0 fdm=marker:
#include <systemc.h>
#include <iostream>
#include "/*{SUBMODULE}*/.h"
using std::cout;
using std::endl;
unsigned errors = 0; // global for use registering errors
char* simulation_name = "/*{SIMULATION_NAME}*/";
int sc_main(int argc, char* argv[]) {
  cout << "INFO: Elaborating "<< simulation_name << endl;
  // Establish time
  sc_set_time_resolution(1,SC_PS);
  sc_set_default_time_unit(1,SC_NS);
  // Clocks & Time constants
  // Submodule & channel declaration and allocation
  /*{SUBMODULE}*/ /*{SUBMODULE}*/_i("/*{SUBMODULE}*/_i");
  // Connectivity
  /*{SUBMODULE}*/_i./*{PIN_NAME}*/(/*{PORT_OR_CHAN}*/);
  cout << "INFO: Simulating "<< simulation_name << endl;
  sc_start();
  cout << "INFO: Post-processing "<< simulation_name << endl;
  // Post processing here
  // Final error report
  cout << "INFO: Simulation " << simulation_name
       << " " << (errors?"FAILED":"PASSED")
       << " with " << errors << " errors"
       << endl;
  return errors?1:0;
}
//Portions COPYRIGHT (C) 2004 Eklectic Ally, Inc.------------------{{{//
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//-----------------------------------------------------------------}}}//
//END $Id: main_direct.cpp,v 1.2 2004/02/21 21:04:35 dcblack Exp $

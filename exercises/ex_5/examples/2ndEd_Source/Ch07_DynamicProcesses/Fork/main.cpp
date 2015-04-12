//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See Fork.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>

const char* simulation_name = "Fork";
using std::cout;
using std::endl;
#include <systemc>
using namespace sc_core;
using namespace std;
#include "Fork.h"

unsigned errors = 0;

int sc_main(int argc, char* argv[]) 
{
  cout << "INFO: " << simulation_name << endl;
  cout << "INFO: Elaborating "<< simulation_name << endl;
  sc_set_time_resolution(1,SC_MS);
  
  Fork Fork_i("Fork_i");
  
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

// Portions COPYRIGHT (C) 2003-2009 ESLX Inc--------------------------//
// Permission granted for anybody to use this example provided this   //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//--------------------------------------------------------------------//

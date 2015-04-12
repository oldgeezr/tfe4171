//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See gas_station.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>
#include "gas_station.h"

using namespace sc_core; 

unsigned errors = 0;
const char* simulation_name = "gas_station";

int sc_main(int argc, char* argv[]) 
{
  sc_set_time_resolution(1,SC_NS);
  // sc_set_default_time_unit(1,SC_NS); deprecated
  
  gas_station Charlies("Charlies",10, 12, 1.5, 10);
  
  cout << "INFO: Starting gas_station simulation" << endl;
  
  sc_start();
  if (not sc_end_of_simulation_invoked()) sc_stop(); //< invoke end_of_simulation
  
  cout << "INFO: Exiting gas_station simulation" << endl;
  cout << "INFO: Simulation " << simulation_name
       << " " << (errors?"FAILED":"PASSED")
       << " with " << errors << " errors"
       << endl;
  
  return errors?1:0;
}

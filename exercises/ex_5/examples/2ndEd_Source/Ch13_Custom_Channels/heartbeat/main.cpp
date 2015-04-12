//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See heartbeat.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
using std::cout;
using std::endl;

#include <systemc>
using namespace sc_core;
using std::cout;
using std::endl;
#include "heartbeat.h"
#include "ea_heartbeat.h"

unsigned errors = 0;
char* simulation_name = "heartbeat";

int sc_main(int argc, char* argv[]) 
{
  cout << "INFO: Elaborating "<< simulation_name << endl;
  //sc_set_time_resolution(1,SC_PS);
  sc_set_default_time_unit(100,SC_PS);
  sc_time timeout(2,SC_NS);
  ea_heartbeat clock("clock");
  heartbeat heartbeat_i("heartbeat_i");
  heartbeat_i.clock(clock);
  
  cout << "INFO: Simulating "<< simulation_name << endl;
  sc_start(timeout);
  if (not sc_end_of_simulation_invoked()) sc_stop(); //< invoke end_of_simulation
  
  cout << "INFO: Post-processing "<< simulation_name << endl;
  cout << "INFO: Simulation " << simulation_name
       << " " << (errors?"FAILED":"PASSED")
       << " with " << errors << " errors"
       << endl;
  return errors?1:0;
}// end sc_main

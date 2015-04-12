//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See manage.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
using std::cout;
using std::endl;

#include <systemc>
using namespace sc_core;
using std::cout;
using std::endl;

#include "manage.h"
#include <string>
using std::string;
#include <map>
std::map<string,string> cfg;

unsigned errors = 0;
string simulation_name = "manage";

int sc_main(int argc, char* argv[]) 
{
  std::ifstream cf("manage.cfg");
  if (!!cf) {
    cout << "INFO: Reading configuration "<< simulation_name << endl;
    string inst, model;
    while (cf >> inst) {
      cout << "'" << inst << "'" << endl;
      if (cf >> model) {
        cfg[inst] = model;
      }//endif
    }//endwhile
  }//endif
  
  cout << "INFO: Elaborating "<< simulation_name << endl;
  //sc_set_time_resolution(1,SC_PS);
  //sc_set_default_time_unit(1,SC_NS);
  manage manage_i("manage_i");
  
  cout << "INFO: Simulating "<< simulation_name << endl;
  sc_start();
  if (not sc_end_of_simulation_invoked()) sc_stop(); //< invoke end_of_simulation
  
  cout << "INFO: Post-processing "<< simulation_name << endl;
  cout << "INFO: Simulation " << simulation_name
       << " " << (errors?"FAILED":"PASSED")
       << " with " << errors << " errors"
       << endl;
  return errors?1:0;
  
} // end sc_main

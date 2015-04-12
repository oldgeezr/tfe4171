//BEGIN main.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See manage.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
using std::cout;
using std::endl;

#include <systemc.h>
#include "manage.h"

#include <map>
std::map<sc_string,sc_string> cfg;

unsigned errors = 0;
char* simulation_name = "manage";

int sc_main(int argc, char* argv[]) {
  ifstream cf(sc_string::to_string("%s.cfg",simulation_name).c_str());
  if (!!cf) {
    cout << "INFO: Reading configuration "<< simulation_name << endl;
    sc_string inst, model;
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
  cout << "INFO: Post-processing "<< simulation_name << endl;
  cout << "INFO: Simulation " << simulation_name
       << " " << (errors?"FAILED":"PASSED")
       << " with " << errors << " errors"
       << endl;
  return errors?1:0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: main.cpp,v 1.1 2004/02/29 04:39:35 dcblack Exp $

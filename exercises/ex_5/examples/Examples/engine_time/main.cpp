//BEGIN main.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See engine_time.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>
#include "engine_time.h"

using std::cout;
using std::endl;

unsigned errors = 0;
char* simulation_name = "engine_time";

int sc_main(int argc, char* argv[]) {
  engine_time engine_time_i("engine_time_i");
  cout << "INFO: Starting " << simulation_name << " simulation" << endl;
  sc_set_time_resolution(1,SC_US);
  sc_set_default_time_unit(1,SC_SEC);
  const double CYCLES = 3.5;
  sc_time t_LIMIT(CYCLES/(engine_time_i.RPM*60),SC_SEC);
  cout << "INFO: Limiting simulation to " << t_LIMIT << endl;
  sc_start(t_LIMIT); // Simulate for 3 revolutions
  cout << "INFO: Exiting " << simulation_name << " simulation" << endl;
  cout << "INFO: Simulation " << simulation_name
       << " " << (errors?"FAILED":"PASSED")
       << " with " << errors << " errors"
       << endl;
  return errors?1:0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: main.cpp,v 1.2 2003/11/21 16:38:30 dcblack Exp $

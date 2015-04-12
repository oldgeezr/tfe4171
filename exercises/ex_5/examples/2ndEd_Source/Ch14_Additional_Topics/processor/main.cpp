//FILE: main.cpp (systemc)
//# vim600:set sw=2 tw=0 fdm=marker:
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See processor.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
using std::cout;
using std::endl;

#include <systemc>
using namespace sc_core;
#include "processor.h"
#include "mem_arch.h"
#include "ea_heartbeat.h"
#include "ea_pullup.h"
#include "stimulus.h"

unsigned errors = 0;
const char* simulation_name = "processor";
const char* simulation_vers = "$Id$";

int sc_main(int argc, char* argv[]) {
  cout << "INFO: " << simulation_name << " " << simulation_vers << endl;
  cout << "INFO: Elaborating "<< simulation_name << endl;
  sc_set_time_resolution(1,SC_PS);
  sc_set_default_time_unit(1,SC_NS);
  // Instantiate
  sc_time t_PERIOD(10,SC_NS);
  ea_heartbeat       clock("clock",t_PERIOD);
  ea_pullup          reset("reset"); // active low signal
  sc_signal<bool>    abort("abort");
  mem_arch           mem("mem",0,8192);
  processor          processor_i("processor_i");
  stimulus           stimulus_i("stimulus_i");
  // Connect
  processor_i.clock_p(clock);
  processor_i.reset_p(reset);
  processor_i.abort_p(abort);
  processor_i.bus_p(mem);
  stimulus_i.bus_p(mem);
  stimulus_i.reset_p(reset);
  stimulus_i.abort_p(abort);
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

//Portions COPYRIGHT (C) 2003-2004 Eklectic Ally, Inc.-------------{{{//
// Permission granted for anybody to use this example provided this   //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//-----------------------------------------------------------------}}}//
//END $Id$

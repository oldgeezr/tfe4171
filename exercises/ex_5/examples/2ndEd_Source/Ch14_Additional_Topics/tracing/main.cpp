//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See tracing.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>
#include "tracing.h"
#include <iostream>
using namespace std;
using namespace sc_core;
using namespace sc_dt;

#include <set>
#include <string>
using std::string;
#include <sstream>
#include <iomanip>

std::set<string> trace_cfg;
sc_trace_file* tf;
std::ostringstream trace_filename;

unsigned errors = 0;
const char* simulation_name = "tracing";
const char* simulation_vers = "$Id$";

int sc_main(int argc, char* argv[]) 
{
  if (argc == 2 and string(argv[1]) == string("--trace")) {
    cout << "INFO: Turning trace on" << endl;
    trace_filename << simulation_name << ".tcfg";
    std::ifstream cf(trace_filename.str().c_str());
    if (!!cf) {
      cout << "INFO: Reading trace configuration "<< simulation_name << endl;
      string inst;
      while (cf >> inst) {
        trace_cfg.insert(inst);
      }//endwhile
      tf = sc_create_vcd_trace_file(simulation_name);
    } else {
      cout << "WARN: No trace configuration file ("<< trace_filename << ". Ignoring." << endl;
    }//endif
  }//endif
  
  cout << "INFO: " << simulation_name << " " << simulation_vers << endl;
  cout << "INFO: Elaborating "<< simulation_name << endl;
  //sc_set_time_resolution(1,SC_PS);
  //sc_set_default_time_unit(1,SC_NS);
  const sc_time t_CLK(10,SC_NS);
  sc_clock clock("clock",t_CLK);
  tracing tracing_i("tracing_i",clock);
  tracing_i.clock_ip(clock);
  if (trace_cfg.find("main")!=trace_cfg.end()) {
    cout << "INFO: -- Tracing 'main'" << endl;
    sc_trace(tf,clock,"clock");
  }//endif
  
  cout << "INFO: Simulating "<< simulation_name << endl;
  sc_start();
  if (not sc_end_of_simulation_invoked()) sc_stop(); //< invoke end_of_simulation
  
  cout << "INFO: Post-processing "<< simulation_name << endl;
  if (!!tf) {
    sc_close_vcd_trace_file(tf);
    cout << "INFO: Wrote " << simulation_name << ".vcd" << endl;
  }//endif 
  cout << "INFO: Simulation " << simulation_name
       << " " << (errors?"FAILED":"PASSED")
       << " with " << errors << " errors"
       << endl;
  return errors?1:0;
  
} // end sc_main

// Portions COPYRIGHT (C) 2003-2009 ESLX Inc.------------------------ //
// Permission granted for anybody to use this example provided this   //
// acknowledgement of ESLX Inc. remains.                              //
//------------------------------------------------------------------- //

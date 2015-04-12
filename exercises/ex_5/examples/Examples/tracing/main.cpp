//FILE: main.cpp (systemc)
//# vim600:set sw=2 tw=0 fdm=marker:
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See tracing.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
using std::cout;
using std::endl;

#include <systemc.h>
#include "tracing.h"

#include <set>
std::set<sc_string> trace_cfg;
sc_trace_file* tf;

unsigned errors = 0;
char* simulation_name = "tracing";
char* simulation_vers = "$Header: /eklectICally/Project/ea/Cvsroot/Book2003/Examples/tracing/main.cpp,v 1.1 2004/02/29 04:40:16 dcblack Exp $";

int sc_main(int argc, char* argv[]) {
  if (argc == 2 && strcmp(argv[1],"--trace")==0) {
    cout << "INFO: Turning trace on" << endl;
    sc_string trace_filename(sc_string::to_string("%s.tcfg",simulation_name));
    ifstream cf(trace_filename.c_str());
    if (!!cf) {
      cout << "INFO: Reading trace configuration "<< simulation_name << endl;
      sc_string inst;
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
  cout << "INFO: Post-processing "<< simulation_name << endl;
  if (!!tf) {
    sc_close_vcd_trace_file(tf);
    cout << "INFO: Wrote " << simulation_name << ".vcd" << endl;
  }//endif }}}
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
//END $Id: main.cpp,v 1.1 2004/02/29 04:40:16 dcblack Exp $

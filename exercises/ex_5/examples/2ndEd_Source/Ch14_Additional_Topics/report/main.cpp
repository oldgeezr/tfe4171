//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See report.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
using std::cout;
using std::endl;

#include <systemc>
using namespace sc_core;
#include "report.h"

const char* simulation_name = "report";
const char* simulation_vers = "$Id$";

int sc_main(int argc, char* argv[]) 
{
  sc_report_handler::set_log_file_name("report-run.log");
  sc_report_handler::stop_after(SC_ERROR, 2);
  sc_report_handler::set_actions(simulation_name,
                                 SC_INFO,
                                 SC_CACHE_REPORT|SC_LOG);
  SC_REPORT_INFO(simulation_name,simulation_vers);
  SC_REPORT_INFO(simulation_name,"Elaborating");
  //sc_set_time_resolution(1,SC_PS);
  //sc_set_default_time_unit(1,SC_NS);
  report report_i("report_i");
  
  SC_REPORT_INFO(simulation_name,"Simulating");
  sc_start();
  if (not sc_end_of_simulation_invoked()) sc_stop(); //< invoke end_of_simulation
  
  SC_REPORT_INFO(simulation_name,"Post-processing");
  sc_report* rp = sc_report_handler::get_cached_report();
  if ( rp ) {
      cout << rp->get_msg() << endl;
      cout << "Simulation " << simulation_name << " FAILED" << endl;
      return 1;
  } else {
      cout << "Simulation " << simulation_name << " PASSED" << endl;
      return 0;
  }//endif
  
} // end sc_main

// Portions COPYRIGHT (C) 2003-2009 ESLX Inc. ----------------------- //
// Permission granted for anybody to use this example provided this   //
// acknowledgement of ESLX Inc. remains.                              //
//------------------------------------------------------------------- //

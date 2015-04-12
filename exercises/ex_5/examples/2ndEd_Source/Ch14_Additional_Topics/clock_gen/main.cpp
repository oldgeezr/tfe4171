//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See clock_gen.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
using std::cout;
using std::endl;

#include <systemc>
using namespace sc_core;
using std::cout;
using std::endl;
#include "clock_gen.h"
#include "monitor.h"

unsigned errors = 0;
const char* simulation_name = "clock_gen";

int sc_main(int argc, char* argv[]) 
{
  cout << "INFO: Elaborating "<< simulation_name << endl;
  //sc_set_time_resolution(1,SC_PS);
  //sc_set_default_time_unit(1,SC_NS);
  sc_signal<bool> clk1;
  clock_gen clock_gen_i("clock_gen_i");
  clock_gen_i.clk1_p(clk1);
  monitor monitor_i("monitor_i");
  monitor_i.clk1_p(clk1);
  monitor_i.clk2_p(clock_gen_i.clk2_p);
  
  cout << "INFO: Simulating "<< simulation_name << endl;
  sc_start(50,SC_NS);
  if (not sc_end_of_simulation_invoked()) sc_stop(); //< invoke end_of_simulation
  
  cout << "INFO: Post-processing "<< simulation_name << endl;
  cout << "INFO: Simulation " << simulation_name
       << " " << (errors?"FAILED":"PASSED")
       << " with " << errors << " errors"
       << endl;
  return errors?1:0;
} // end sc_main

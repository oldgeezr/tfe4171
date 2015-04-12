//BEGIN main.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See lfsr_ex.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
using std::cout;
using std::endl;

#include <systemc.h>
#include "lfsr_ex.h"
#include "test_lfsr.h"

unsigned errors = 0;
char* simulation_name = "lfsr_ex";

int sc_main(int argc, char* argv[]) {
  cout << "INFO: Elaborating "<< simulation_name << endl;
  //sc_set_time_resolution(1,SC_PS);
  //sc_set_default_time_unit(1,SC_NS);
  // Channels to connect test to design
  sc_signal<bool> sample;
  sc_clock clock("clock",sc_time(10,SC_NS));
  sc_signal<bool> reset;
  sc_signal<sc_uint<32> > signature;
  // Instantiate design and testbench
  lfsr_ex   lfsr_ex_i("lfsr_ex_i");
    lfsr_ex_i.sample(sample);
    lfsr_ex_i.clock(clock);
    lfsr_ex_i.reset(reset);
    lfsr_ex_i.signature(signature);
  test_lfsr test_lfsr_i("test_lfsr_i");
    test_lfsr_i.sample(sample);
    test_lfsr_i.clock(clock);
    test_lfsr_i.reset(reset);
    test_lfsr_i.signature(signature);
  // Setup wave form tracing
  sc_trace_file* tf;
  if (argc == 2 and strcmp(argv[1],"-trace") == 0) {
    cout << "INFO: Turning on tracing..."<< endl;
    tf = sc_create_vcd_trace_file("lfsr_ex");
    sc_trace(tf,clock,"clock");
    sc_trace(tf,sample,"sample");
    sc_trace(tf,reset,"reset");
    sc_trace(tf,signature,"signature");
  }//endif
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
//END $Id: main.cpp,v 1.2 2004/02/09 13:02:13 dcblack Exp $

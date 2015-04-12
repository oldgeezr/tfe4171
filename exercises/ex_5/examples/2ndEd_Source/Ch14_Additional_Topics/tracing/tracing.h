#ifndef TRACING_H
#define TRACING_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This example illustrates the use of basic signal tracing. Action
//   occurs in both main.cpp and here. Notice the use of argv to turn
//   tracing on/off, and the use of map to aid the selection of what
//   to trace. All of the activity/processing is bogus, and simply
//   present to generate some waveform activity.
//
// DESIGN HIERARCHY
//   sc_main()
//   +- tracing_i
//      +- tracing_thread
//      +- counter_i
//      |  +- count_method
//      +- arbitrator_i
//         +- arbitrator_thread
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <systemc>
// Submodule class declarations
struct counter;
struct arbitrator;

SC_MODULE(tracing) 
{
  // Ports
  sc_core::sc_in_clk              clock_ip;
  
  // Local channels      
  sc_core::sc_signal<unsigned>    addr_sig;
  sc_core::sc_signal<int>         data_snd_sig;
  sc_core::sc_signal<int>         data_rcv_sig;
  sc_core::sc_signal<bool>        request_sig;
  sc_core::sc_signal<bool>        grant_sig;
  sc_core::sc_signal<sc_dt::sc_uint<2> > transact_sig;
  
  // Local channel & submodule declarations
  counter*    counter_i;
  arbitrator* arbitrator_i;
  
  // Constructor declarations
  tracing(sc_core::sc_module_name nm,sc_core::sc_clock& clock);
  
  // Process declarations
  void tracing_thread();
  
  // Helper functions
  void write(unsigned addr, int data);
  int read(unsigned addr);
  
};
#endif
// Portions COPYRIGHT (C) 2004-2009 ESLX Inc.------------------------ //
// Permission granted for anybody to use this template provided this  //
// acknowledgement of ESLX.com remains.                               //
//------------------------------------------------------------------- //

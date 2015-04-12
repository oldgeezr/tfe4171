#ifndef TRACING_H
#define TRACING_H
//FILE: tracing.h (systemc)
//# vim600:sw=2:tw=0:fdm=marker
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
// Submodule class declarations
struct counter;
struct arbitrator;
// Module definition
SC_MODULE(tracing) {
  // Ports
  sc_in_clk              clock_ip;
  // Local channels      
  sc_signal<unsigned>    addr_sig;
  sc_signal<int>         data_snd_sig;
  sc_signal<int>         data_rcv_sig;
  sc_signal<bool>        request_sig;
  sc_signal<bool>        grant_sig;
  sc_signal<sc_uint<2> > transact_sig;
  // Local channel & submodule declarations
  counter*    counter_i;
  arbitrator* arbitrator_i;
  // Constructor declarations
  tracing(sc_module_name nm,sc_clock& clock);//Constructor
  // Process declarations
  void tracing_thread();
  // Helper functions
  void write(unsigned addr, int data);
  int read(unsigned addr);
};
#endif
//Portions COPYRIGHT (C) 2004 Eklectic Ally, Inc.------------------{{{//
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. <www.eklect.com> remains.   //
//-----------------------------------------------------------------}}}//
//END $Id: tracing.h,v 1.2 2004/04/15 17:45:36 dcblack Exp $

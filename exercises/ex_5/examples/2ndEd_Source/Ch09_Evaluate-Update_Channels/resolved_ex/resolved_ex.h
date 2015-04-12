#ifndef RESOLVED_EX_H
#define RESOLVED_EX_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   TO_BE_SUPPLIED
//
// DESIGN HIERARCHY
//   sc_main()
//   +- resolved_ex_i
//    +- master_thread
//    +- slave_thread
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>

SC_MODULE(resolved_ex) 
{
  sc_core::sc_signal_resolved request_sig;
  sc_core::sc_signal<bool> ack0_sig;
  sc_core::sc_signal<bool> ack1_sig;
  sc_core::sc_signal_rv<8> addr, data;
  
  SC_CTOR(resolved_ex)
  : t_1NS(1,sc_core::SC_NS)
  , ZZ("zzzzzzzz")
  {
    SC_THREAD(master1_thread);
    SC_THREAD(master2_thread);
    SC_THREAD(slave_thread);
  }
  
  void master1_thread(void);
  void master2_thread(void);
  void slave_thread(void);
  // Local constants
  const sc_core::sc_time t_1NS;
  const sc_dt::sc_lv<8> ZZ;
};

#endif
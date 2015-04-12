#ifndef SWITCH_H
#define SWITCH_H
//BEGIN switch.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   TO_BE_SUPPLIED
//
// DESIGN HIERARCHY
//   sc_main()
//   +- board_i
//      +- switch_i
//       +- switch_thread
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>

SC_MODULE(Switch) {
  sc_port<sc_fifo_in_if<int>,4> T1_ip;
  sc_port<sc_signal_out_if<bool>,0> request_op;
  SC_CTOR(Switch) {
    SC_THREAD(switch_thread);
  }
  void switch_thread(void);
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: switch.h,v 1.3 2004/04/15 17:45:16 dcblack Exp $

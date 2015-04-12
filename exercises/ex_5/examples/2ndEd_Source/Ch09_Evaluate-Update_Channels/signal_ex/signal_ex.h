#ifndef SIGNAL_EX_H
#define SIGNAL_EX_H
//BEGIN signal_ex.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This example illustrates sc_signal evaluate-update behavior. There
//   are two variables (count & temp) and two signals (count_sig &
//   message_sig). Notice how ordinary variables update immediately;
//   whereas, signals require at least a delta-cycle delay (i.e.
//   wait(SC_ZERO_TIME);). Most of the action occurs in the process
//   signal_ex_thread, which reads and writes to these variable
//   and signals. The process signal_ex_method simply monitors the
//   associated events.
//
// DESIGN HIERARCHY
//   sc_main()
//   +- signal_ex_i
//    +- signal_ex_thread
//    +- signal_ex_method
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>
#include <string>

// Following required to allow sc_signal<std::string>...
namespace sc_core {
  void sc_trace(sc_core::sc_trace_file* tf, const std::string& val, const std::string& nm);
}

SC_MODULE(signal_ex) {
  enum color {BLACK, RED, GREEN, BLUE, YELLOW, MAGENTA, CYAN, WHITE};
  // Local data variables
  int                             count;       
  color                           traffic_temp;
  std::string                     message_temp;
  // Local channels
  sc_core::sc_signal<int>         count_sig;  
  sc_core::sc_signal<color>       traffic_sig;
  sc_core::sc_signal<std::string> message_sig;
  // Constructor
  SC_CTOR(signal_ex)
  {
    SC_THREAD(signal_ex_thread);
    SC_METHOD(signal_ex_method);
      sensitive << count_sig
                << traffic_sig
                << message_sig;
  }
  void signal_ex_thread(void);
  void signal_ex_method(void);
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id$

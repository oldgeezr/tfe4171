#ifndef TIME_FLIES_H
#define TIME_FLIES_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This example demonstrates sc_time and associated functions to
//   manipulate and display time as managed by the SystemC simulator.
//   Some aspects are found in main.cpp, while most are in the
//   implementation file, time_flies.cpp. Notice the use of a helper
//   function, display_hms(), which incidentally might be better 
//   implemented as a global function, but serves here to illustrate
//   the point that helper functions can be quite simple.
//
// DESIGN HIERARCHY
//   sc_main()
//   +- time_flies_i
//    +- time_thread
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>

SC_MODULE(time_flies) 
{
  SC_CTOR(time_flies) 
  {
    SC_THREAD(time_thread);
  }
  
  void time_thread(void);
  std::string display_hms( const sc_core::sc_time t);
};
#endif
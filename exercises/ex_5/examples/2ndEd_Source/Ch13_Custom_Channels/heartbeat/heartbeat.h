#ifndef HEARTBEAT_H
#define HEARTBEAT_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This example uses the ea_heartbeat hierarchical channel, which
//   models a very simple clock.
//
// DESIGN HIERARCHY
//   sc_main()
//   +- ea_heartbeat clock
//   +- heartbeat_i(clock)
//    +- heartbeat_method
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>
#include "ea_heartbeat_if.h"

SC_MODULE(heartbeat) 
{
  sc_port<ea_heartbeat_if> clock;
  
  // Constructor
  SC_CTOR(heartbeat)
  {
    SC_METHOD(heartbeat_method);
      sensitive << clock;
      dont_initialize();
  }
  
  void heartbeat_method(void);
};

#endif
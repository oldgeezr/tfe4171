#ifndef METHOD_DELAY_H
#define METHOD_DELAY_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This example illustrates how to insert time delays into SC_METHODs.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>

extern const sc_core::sc_time FIVE;

SC_MODULE(method_delay) 
{
  enum states {INIT, FIVE_1, FIVE_2, ZERO_1, ZERO_2, STOP};
  int state;
  
  SC_CTOR(method_delay) 
  : state(INIT) 
  {
    SC_METHOD(delay_method);
  }
  void delay_method(void);
};
#endif
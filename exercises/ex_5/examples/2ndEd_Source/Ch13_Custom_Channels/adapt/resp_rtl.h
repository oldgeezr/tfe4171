#ifndef RESP_RTL_H
#define RESP_RTL_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// See interrupt.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>

SC_MODULE(resp_rtl) 
{
  sc_in<bool> irq_ip;
  
  // Constructor
  SC_CTOR(resp_rtl)
  {
    SC_METHOD(resp_method);
      sensitive << irq_ip;
      dont_initialize();
  }
  
  void resp_method(void);
};

#endif
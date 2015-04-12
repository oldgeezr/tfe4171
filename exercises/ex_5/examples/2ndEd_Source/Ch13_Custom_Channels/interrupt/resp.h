#ifndef RESP_H
#define RESP_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// See interrupt.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>
#include "ea_interrupt_evt_if.h"

SC_MODULE(resp) 
{
  sc_port<ea_interrupt_evt_if> irq_ip;
  
  // Constructor
  SC_CTOR(resp)
  {
    SC_METHOD(resp_method);
     sensitive << irq_ip;
     dont_initialize();
  }
  
  void resp_method(void);
};

#endif

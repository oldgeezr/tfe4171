#ifndef STIM_H
#define STIM_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// See interrupt.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>
#include "ea_interrupt_gen_if.h"

SC_MODULE(stim) 
{
  sc_port<ea_interrupt_gen_if> irq_op;
  
  // Constructor
  SC_CTOR(stim)
  {
    SC_THREAD(stim_thread);
  }
  
  void stim_thread(void);
};

#endif

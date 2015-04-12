#ifndef SRC_H
#define SRC_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   See fifo_of_ptr.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>
#include "mydata.h"

SC_MODULE(src) 
{
  sc_core::sc_fifo_out<mydata*> out;
  SC_CTOR(src)
  : count(0) 
  {
    SC_THREAD(src_thread);
  }
  
  void src_thread(void);
  unsigned count;
};

#endif
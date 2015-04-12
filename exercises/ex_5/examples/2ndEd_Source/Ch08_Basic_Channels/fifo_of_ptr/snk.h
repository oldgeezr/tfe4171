#ifndef SNK_H
#define SNK_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   See fifo_of_ptr.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>
#include <cmath>
#include "mydata.h"

SC_MODULE(snk) 
{
  sc_core::sc_fifo_in<mydata*> in;
  SC_CTOR(snk)
  :count(0) 
  {
    SC_METHOD(snk_method);
      sensitive << in.data_written();
      dont_initialize();
  }
  
  void snk_method(void);
  int count;
};

#endif
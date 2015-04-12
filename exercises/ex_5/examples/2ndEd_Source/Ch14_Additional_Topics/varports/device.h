#ifndef DEVICE_H
#define DEVICE_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// See varports.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>

SC_MODULE(device)
{
  sc_fifo_in<int>  rcv_p;
  sc_fifo_out<int> xmt_p;
  
  // Constructor
  SC_CTOR(device)
  {
    SC_THREAD(rcv_thread);
    SC_THREAD(xmt_thread);
  }
  
  void rcv_thread();
  void xmt_thread();
};

#endif
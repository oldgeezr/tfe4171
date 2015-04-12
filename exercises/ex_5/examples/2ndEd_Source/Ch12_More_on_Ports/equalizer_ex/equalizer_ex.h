#ifndef EQUALIZER_EX_H
#define EQUALIZER_EX_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This example illustrates the use of specialized ports (Chapter 12)
//   to use event finders. It is brief and to the point.
//
// DESIGN HIERARCHY
//   sc_main()
//   +- equalizer_ex_i
//    +- equalizer_ex_PROCESS
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>

SC_MODULE(equalizer_ex) 
{
  sc_fifo_in<double>  raw_fifo_ip;      
  sc_fifo_out<double> equalized_fifo_op;
  
  SC_CTOR(equalizer_ex) 
  {
    SC_THREAD(equalizer_thread);
      sensitive << raw_fifo_ip.data_written();
  }
  
  void equalizer_thread(void);
};

#endif
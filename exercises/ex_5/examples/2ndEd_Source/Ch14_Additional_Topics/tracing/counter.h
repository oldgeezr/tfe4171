#ifndef counter_H
#define counter_H

#include <systemc>
SC_MODULE(counter) 
{
  // Ports
  sc_core::sc_in<sc_dt::sc_uint<2> >  transact_ip;
  sc_core::sc_in<unsigned>    addr_ip;
  sc_core::sc_in<int>         data_in_ip;
  sc_core::sc_out<int>        data_out_op;
  
  // Constructor declaration
  SC_CTOR(counter);
  
  // Processe declarations
  void counter_thread();
  enum transaction {IDLE, READ, WRITE};
};
#endif
// Portions COPYRIGHT (C) 2004-2009 ESLX Inc.------------------------ //
// Permission granted for anybody to use this template provided this  //
// acknowledgement of ESLX Inc. remains.                              //
//------------------------------------------------------------------- //

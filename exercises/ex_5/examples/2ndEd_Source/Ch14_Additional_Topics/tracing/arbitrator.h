#ifndef arbitrator_H
#define arbitrator_H
#include <systemc>

SC_MODULE(arbitrator) 
{
  // Ports
  sc_core::sc_in<bool>  request_ip;
  sc_core::sc_out<bool> grant_op;  
  sc_core::sc_in_clk    clock_ip; 
  
  // Constructor
  arbitrator(sc_core::sc_module_name nm,sc_core::sc_clock& clock);
  
  // Processe declarations
  void arbitrator_thread();
  
private:
  sc_core::sc_clock& m_clock;
};
#endif
// Portions COPYRIGHT (C) 2004-2009 ESLX Inc.------------------------ //
// Permission granted for anybody to use this template provided this  //
// acknowledgement of ESLX Inc. remains.                              //
//------------------------------------------------------------------- //
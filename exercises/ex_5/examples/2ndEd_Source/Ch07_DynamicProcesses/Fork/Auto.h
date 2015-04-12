//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// See Fork.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef AUTO_H 
#define AUTO_H
#include <string>
// Module definition
SC_MODULE(Auto) 
{
  sc_fifo_in<double> wheel_lf_ip;
  sc_fifo_in<double> wheel_rt_ip;
  // Constructor declarations
  SC_HAS_PROCESS(Auto);
  Auto(sc_module_name nm, double base_length);
  // Process declarations
  void Auto_thread();
private:
  // Local data
  double m_base_length;
  
};
#endif
// Portions COPYRIGHT (C) 2004-2009 ESLX Inc.------------------------ //
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//------------------------------------------------------------------- //
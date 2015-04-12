//FILE: Auto.h (systemc)
//# vim600:sw=2:tw=0:fdm=marker
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// See Fork.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef AUTO_H #define AUTO_H
#include <string>
// Module definition
SC_MODULE(Auto) {
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
//Portions COPYRIGHT (C) 2004 Eklectic Ally, Inc.------------------{{{//
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//-----------------------------------------------------------------}}}//
//END $Id: Auto.h,v 1.2 2004/03/04 00:37:45 dcblack Exp $

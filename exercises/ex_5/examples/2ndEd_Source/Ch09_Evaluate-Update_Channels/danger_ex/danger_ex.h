#ifndef DANGER_EX_H
#define DANGER_EX_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This example illustrates two issues, one of which is undetected
//   by SystemC.
//
// DESIGN HIERARCHY
//   sc_main()
//   +- danger_ex_i
//    +- danger_ex_thread
//    +- collide_ex_thread
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>

SC_MODULE(danger_ex) 
{
  const sc_core::sc_time t_1NS;
  sc_core::sc_signal<double> x, y, r, a;
  SC_CTOR(danger_ex)
  : t_1NS(1,sc_core::SC_NS)
  {
    SC_THREAD(danger_ex_thread);
    SC_THREAD(collide_ex_thread);
  }
  void danger_ex_thread(void);
  void collide_ex_thread(void);
};

#endif

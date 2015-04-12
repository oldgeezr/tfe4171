#ifndef SHIFT_REGISTER_H
#define SHIFT_REGISTER_H
//BEGIN shift_register.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   TO_BE_SUPPLIED
//
// DESIGN HIERARCHY
//   sc_main()
//   +- shift_register_i
//    +- flop1_thread
//    +- flop2_thread
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>

SC_MODULE(shift_register) {
  const sc_time t_SEC;
  int m_i1; // input register
  int m_i2;
  int m_i3;
  int m_i4; // output register
  sc_signal<int> m_q1; // input register
  sc_signal<int> m_q2;
  sc_signal<int> m_q3;
  sc_signal<int> m_q4; // output register
  sc_event e_q1;
  sc_event e_q2;
  sc_event e_q3;
  sc_event e_q4;
  SC_CTOR(shift_register) :
    m_i1(0), m_i2(0), m_i3(0), m_i4(0),
    m_q1(0), m_q2(0), m_q3(0), m_q4(0),
    t_SEC(1,SC_SEC)
  {
    SC_THREAD(flop3_thread);
    SC_THREAD(flop4_thread);
    SC_THREAD(flop1_thread);
    SC_THREAD(flop2_thread);
    SC_THREAD(monitor_thread);
  }
  void flop1_thread(void);
  void flop2_thread(void);
  void flop3_thread(void);
  void flop4_thread(void);
  void monitor_thread(void);
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: shift_register.h,v 1.3 2004/04/15 17:44:49 dcblack Exp $

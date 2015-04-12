#ifndef WHEEL_H
#define WHEEL_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See sedan.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>

SC_MODULE(Wheel) {
  SC_HAS_PROCESS(Wheel);
  Wheel(sc_module_name nm);
  void Wheel_thread(void);
};

#endif
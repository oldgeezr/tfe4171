#ifndef EXHAUST_H
#define EXHAUST_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See sedan.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>

SC_MODULE(Exhaust) 
{
  SC_HAS_PROCESS(Exhaust);
  Exhaust(sc_module_name nm);
  void Exhaust_thread(void);
};

#endif
#ifndef FUELMIX_H
#define FUELMIX_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See sedan.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>

SC_MODULE(FuelMix) 
{
  SC_HAS_PROCESS(FuelMix);
  FuelMix(sc_module_name nm);
  void FuelMix_thread(void);
};

#endif
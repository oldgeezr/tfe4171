#ifndef FUELMIX_H
#define FUELMIX_H
//BEGIN FuelMix.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See sedan.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>

SC_MODULE(FuelMix) {
  SC_HAS_PROCESS(FuelMix);
  FuelMix(sc_module_name nm);
  void FuelMix_thread(void);
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: FuelMix.h,v 1.4 2004/04/15 17:38:14 dcblack Exp $

#ifndef FUELMIX_H
#define FUELMIX_H
//BEGIN FuelMix.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See jalopy.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>

SC_MODULE(FuelMix) {
  SC_CTOR(FuelMix) {
    cout << "INFO: Constructing instance " << name() << endl;
    SC_THREAD(FuelMix_thread);
  }//end FuelMix constructor
  void FuelMix_thread(void) {
    cout << "INFO: Ran FuelMix_thread inside instance " << name() << endl;
  }//end FuelMix_thread()
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: FuelMix.h,v 1.1 2004/01/12 03:34:15 dcblack Exp $

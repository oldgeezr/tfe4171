//BEGIN FuelMix.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See FuelMix.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "FuelMix.h"

// Constructor
FuelMix::FuelMix(sc_module_name nm)
: sc_module(nm)
{
  cout << "INFO: Constructing instance " << name() << endl;
  SC_THREAD(FuelMix_thread);
}//end FuelMix constructor

void FuelMix::FuelMix_thread(void) {
  cout << "INFO: Ran FuelMix_thread inside instance " << name() << endl;
}//end FuelMix_thread()

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: FuelMix.cpp,v 1.4 2004/03/04 21:04:07 dcblack Exp $

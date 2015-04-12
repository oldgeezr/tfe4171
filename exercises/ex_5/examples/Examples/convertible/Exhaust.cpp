//BEGIN Exhaust.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See sedan.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "Exhaust.h"

// Constructor
Exhaust::Exhaust(sc_module_name nm)
: sc_module(nm)
{
  cout << "INFO: Constructing instance " << name() << endl;
  SC_THREAD(Exhaust_thread);
}//end Exhaust()

void Exhaust::Exhaust_thread(void) {
  cout << "INFO: Ran Exhaust_thread inside instance " << name() << endl;
}//end Exhaust_thread()

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: Exhaust.cpp,v 1.4 2004/03/04 21:04:07 dcblack Exp $

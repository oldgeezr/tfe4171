#ifndef Engine_H
#define Engine_H
//BEGIN Engine.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See jalopy.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>
#include "FuelMix.h"
#include "Exhaust.h"
#include "Cylinder.h"

SC_MODULE(Engine) {
  // Sub-module instances
  FuelMix fuelmix_i;
  Exhaust exhaust_i;
  Cylinder cyl_i1;
  Cylinder cyl_i2;
  // Constructor
  SC_CTOR(Engine) :
    fuelmix_i("fuelmix_i"),
    exhaust_i("exhaust_i"),
    cyl_i1("cyl_i1"),
    cyl_i2("cyl_i2")
  {
    cout << "INFO: Constructing instance " << name() << endl;
    SC_THREAD(Engine_thread);
  }//end Engine constructor
  // Processes
  void Engine_thread(void) {
    cout << "INFO: Ran Engine_thread inside instance " << name() << endl;
  }//end Engine_thread
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: Engine.h,v 1.1 2004/01/12 03:34:15 dcblack Exp $

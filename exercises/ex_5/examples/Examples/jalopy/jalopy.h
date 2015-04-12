#ifndef JALOPY_H
#define JALOPY_H
//BEGIN jalopy.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This old jalopy Jalopy code illustrates the several direct
//   techniques of instantiation. First, main simply instantiates
//   the top-level jalopy. jalopy illustrates the popular header
//   only submodule technique, while Engine & Body illustrate the
//   separate implementation approach.
//
// DESIGN HIERARCHY
//   sc_main() -- top-level direct
//   +- jalopy_i -- direct header only
//    +- jalopy_thread
//    +- Engine eng_i -- direct separate implementation
//    |  +- FuelMix fuelmix_i
//    |  +- Exhaust exhaust_i
//    |  +- Cylinder cyl_i1
//    |  +- Cylinder cyl_i2
//    +- Body body_i -- direct separate implementation
//       +- Wheel wheel_FL
//       +- Wheel wheel_FR
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>
#include "Engine.h"
#include "Body.h"

SC_MODULE(jalopy) {
  Engine Engine_i;
  Body Body_i;
  SC_CTOR(jalopy)
  : Engine_i("Engine_i"),
    Body_i("Body_i")
  {
    cout << "INFO: Constructing instance " << name() << endl;
    SC_THREAD(jalopy_thread);
  }
  void jalopy_thread(void) {
    cout << "INFO: Ran jalopy_thread inside instance " << name() << endl;
  }//end jalopy_thread()
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: jalopy.h,v 1.1 2004/01/12 03:34:15 dcblack Exp $

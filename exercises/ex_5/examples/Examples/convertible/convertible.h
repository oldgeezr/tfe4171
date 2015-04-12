#ifndef CONVERTIBLE_H
#define CONVERTIBLE_H
//BEGIN convertible.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This new convertible code illustrates the several indirect
//   techniques of instantiation. First, main instantiates
//   the top-level convertible. convertible illustrates the header
//   only submodule technique, while Engine & Body illustrate the
//   separate implementation approach. Notice how Engine and Body
//   require fewer file dependencies.
//
// DESIGN HIERARCHY
//   sc_main() -- top-level indirect
//   +- convertible_i -- indirect header only
//    +- convertible_thread
//    +- Engine eng_i -- indirect separate implementation
//    |  +- FuelMix fuelmix_i
//    |  +- Exhaust exhaust_i
//    |  +- Cylinder cyl_i1
//    |  +- Cylinder cyl_i2
//    +- Body body_i -- indirect separate implementation
//       +- Wheel wheel_FL
//       +- Wheel wheel_FR
//
// FILE HIERARCHY
//   convertible.x
//   +- $SYSTEMC/lib/systemc.a
//   +- main.cpp
//   +- convertible.cpp
//   |  +- convertible.h
//   |     +- Engine.h
//   |     +- Body.h
//   +- Engine.cpp
//   |  +- Engine.h
//   +- Body.cpp
//   |  +- Body.h
//   +- FuelMix.cpp
//   |  +- FuelMix.h
//   +- Exhaust.cpp
//   |  +- Exhaust.h
//   +- Cylinder.cpp
//   |  +- Cylinder.h
//   +- Wheel.cpp
//      +- Wheel.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>
#include "Engine.h"
#include "Body.h"

SC_MODULE(convertible) {
  Engine* Engine_i;
  Body* Body_i;
  SC_CTOR(convertible)
  {
    cout << "INFO: Constructing instance " << name() << endl;
    SC_THREAD(convertible_thread);
    Engine_i = new Engine("Engine_i");
    Body_i = new Body("Body_i");
  }
  void convertible_thread(void);
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: convertible.h,v 1.3 2004/04/15 17:38:23 dcblack Exp $

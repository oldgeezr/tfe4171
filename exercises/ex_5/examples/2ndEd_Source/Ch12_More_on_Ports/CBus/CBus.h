#ifndef CBUS_H
#define CBUS_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This is an example of using an sc_export and
//   hiding implementation of a complex bus. The
//   bus has both a North and a South interface
//   to implement which it implements internally
//   using sc_exports on North_bus and South_bus
//   channels. There is also a hidden Debus_bus
//   interface that the customer doesn't need to
//   know about unless the vendor chooses.
//
//   The vendor need only provide three files:
//   CBus.h CBus_if.h and CBus.o (compiled for
//   the appropriate platform). An optional
//   pair of files Debug_if.h and CBus_debug.h
//   can be provided on an as needed basis.
//
// USER VIEW
//         ____ CBus_North_if
//        /
//   +--()--+
//   | CBus O-- Debug_bus_if (OPTIONAL)
//   +--()--+
//        \____ CBus_South_if
//
//
// IMPLEMENTATION
//
//   +-----(.)--------------------+
//   |      |                     |
//   | +---(.)---+                |
//   | |North_bus|                |
//   | +---(.)---+                |
//   |      |                     |
//   | +---[.]---+  +-----------+ |
//   | |CBus_rtl @--O Debug_bus O-O
//   | +---[.]---+  +-----------+ |
//   |      |                     |
//   | +---(.)---+                |
//   | |South_bus|                |
//   | +---(.)---+                |
//   |      |                     |
//   +-----(.)--------------------+
//
// DESIGN HIERARCHY
//   sc_main()
//   +- CBus_i
//      // Below is mostly hidden to user of CBus.h
//      +- *nbus_ci
//      +- *sbus_ci
//      +- *debug_ci
//      +- *CBus_rtl_ci
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "CBus_if.h"
class North_bus;    class South_bus;
class Debug_bus;    class CBus_rtl;

SC_MODULE(CBus)  
{
  sc_export<CBus_North_if> north_p;
  sc_export<CBus_South_if> south_p;
  SC_CTOR(CBus);
private:
  North_bus* nbus_ci;   South_bus* sbus_ci;
  Debug_bus* debug_ci;  CBus_rtl*  rtl_i;
};
#endif
// Portions COPYRIGHT (C) 2004-2009 ESKX Inc.------------------------ //
// Permission granted for anybody to use this template provided this  //
// acknowledgement of ESLX Inc. remains.                              //
//------------------------------------------------------------------- //
#ifndef PRIMITIVE_H
#define PRIMITIVE_H
//BEGIN primitive.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This is an example of a user defined primitive channel,
//   the Genghis chan'nel <GRIN>.
//
// DESIGN HIERARCHY
//   sc_main()
//   +- primitive_i
//    +- first_thread
//    |       |
//    |       v
//    |  Genghis khan
//    |       |
//    |       v
//    +- second_thread
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>
#include "Genghis.h"

SC_MODULE(primitive) {
  SC_CTOR(primitive)
  {
    SC_THREAD(first_thread);
    SC_THREAD(second_thread);
  }
  void first_thread(void);
  void second_thread(void);
  Genghis khan;
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: primitive.h,v 1.4 2004/04/15 17:43:18 dcblack Exp $

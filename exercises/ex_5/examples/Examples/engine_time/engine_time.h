#ifndef ENGINE_TIME_H
#define ENGINE_TIME_H
//BEGIN engine_time.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This is a sample solution to the engine time model suggested
//   by exercise 5.3.
//
// DESIGN HIERARCHY
//   sc_main()
//   +- engine_time_i
//    +- engine_time_thread_i
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>

SC_MODULE(engine_time) {
  double RPM;
  SC_CTOR(engine_time)
  : RPM(800.0)
  {
    SC_THREAD(engine_time_thread);
  }
  void engine_time_thread(void);
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: engine_time.h,v 1.3 2004/04/15 17:38:33 dcblack Exp $

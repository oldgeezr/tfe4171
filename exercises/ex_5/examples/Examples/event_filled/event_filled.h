#ifndef EVENT_FILLED_H
#define EVENT_FILLED_H
//BEGIN event_filled.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This is an example of various types of events including the
//   new version 2.1 sc_event_queue.
//
// DESIGN HIERARCHY
//   sc_main()
//   +- event_filled_i
//    +- event_filled_PROCESS_i
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
using std::cout;
using std::endl;

#include <systemc.h>

SC_MODULE(event_filled) {
  sc_time t_start;
  sc_event my_event;
#ifdef SYSTEMC_V2_1
  sc_event_queue better_event;
#endif
  SC_CTOR(event_filled)
  :
#ifdef SYSTEMC_V2_1
    better_count(0),
    better_event("better_event"),
#endif
    my_count(0)
  {
    SC_THREAD(event_filled_thread);
    SC_METHOD(monitor_my_method);
      sensitive << my_event;
      dont_initialize();
#ifdef SYSTEMC_V2_1
    SC_METHOD(monitor_better_method);
      sensitive << better_event;
      dont_initialize();
#endif
  }
  void event_filled_thread(void);
  void monitor_my_method(void);
  int my_count;
#ifdef SYSTEMC_V2_1
  void monitor_better_method(void);
  int better_count;
#endif
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: event_filled.h,v 1.5 2004/04/15 17:38:48 dcblack Exp $

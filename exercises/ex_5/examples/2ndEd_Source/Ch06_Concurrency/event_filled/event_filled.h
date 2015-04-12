#ifndef EVENT_FILLED_H
#define EVENT_FILLED_H
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

#include <systemc>

SC_MODULE(event_filled) 
{
  sc_core::sc_time t_start;
  sc_core::sc_event my_event;
  sc_core::sc_event_queue better_event;
  SC_CTOR(event_filled)
  : better_count(0)
  , better_event("better_event")
  , my_count(0)
  {
    SC_THREAD(event_filled_thread);
    
    SC_METHOD(monitor_my_method);
      sensitive << my_event;
      dont_initialize();
    
    SC_METHOD(monitor_better_method);
      sensitive << better_event;
      dont_initialize();
  }
  
  void event_filled_thread(void);
  void monitor_my_method(void);
  int my_count;
  void monitor_better_method(void);
  int better_count;
};

#endif
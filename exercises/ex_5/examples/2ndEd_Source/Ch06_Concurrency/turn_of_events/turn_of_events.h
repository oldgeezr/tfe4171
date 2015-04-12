#ifndef TURN_OF_EVENTS_H
#define TURN_OF_EVENTS_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   Simple example of use of events and sc_threads. Time not modeled.
//
// DESIGN HIERARCHY
//   sc_main()
//   +- turn_of_events_i
//      +- turn_knob_thread
//      +- right_signal_thread
//      +- left_signal_thread
//      +- stop_signal_thread
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>

SC_MODULE(turn_of_events) 
{
  SC_CTOR(turn_of_events) 
  {
    SC_THREAD(turn_knob_thread);
    SC_THREAD(left_signal_thread);
    SC_THREAD(stop_signal_thread);
    SC_THREAD(right_signal_thread);
  }
  
  sc_core::sc_event signal_right, signal_left, signal_stop, signals_off;
  sc_core::sc_event right_blinking, right_off;
  sc_core::sc_event left_blinking, left_off;
  sc_core::sc_event stop_blinking, stop_off;
  
  void turn_knob_thread(void);
  void right_signal_thread(void);
  void left_signal_thread(void);
  void stop_signal_thread(void);
};//endclass turn_of_events

#endif
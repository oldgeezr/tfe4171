//BEGIN event_filled.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See event_filled.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "event_filled.h"

void event_filled::event_filled_thread(void) {
  sc_time t_25NS(25,SC_NS);
  sc_time t_20NS(20,SC_NS);
  sc_time t_15NS(15,SC_NS);
  sc_time t_10NS(10,SC_NS);
  cout << "INFO: Setup my events" << endl;
  my_event.notify(); // 1st event
  my_event.notify(); // lost
  //my_event.cancel(); // nothing to cancel
  my_event.notify(t_20NS); // overwritten
  my_event.notify(t_25NS); // cancelled
  my_event.cancel();
  my_event.notify(t_20NS); // overwritten
  my_event.notify(t_10NS); // overwritten
  my_event.notify(t_15NS); // too late
  my_event.notify(t_10NS); // already there
  my_event.notify(SC_ZERO_TIME); // 3rd actual event
  my_event.notify(SC_ZERO_TIME);
  cout << "INFO: Allow my events" << endl;
  t_start = sc_time_stamp();
  wait(1,SC_US);
#ifdef SYSTEMC_V2_1
  cout << "INFO: Setup better events" << endl;
  //better_event.notify(); // no immediate queued events
  //better_event.notify(); // no immediate queued events
  //better_event.cancel(); // nothing to cancel
  better_event.notify(t_20NS); // cancelled
  better_event.notify(t_25NS); // cancelled
  better_event.cancel_all();
  better_event.notify(t_20NS); // 6th event
  better_event.notify(t_10NS); // 3rd event
  better_event.notify(t_15NS); // 5th event
  better_event.notify(t_10NS); // 4th event
  better_event.notify(SC_ZERO_TIME); // 1st event
  better_event.notify(SC_ZERO_TIME); // 2nd event
  cout << "INFO: Allow better events" << endl;
  t_start = sc_time_stamp();
#endif
  wait(1,SC_MS);
}//end event_filled_thread()

void event_filled::monitor_my_method(void) {
  cout << "INFO: my_event " 
       << ++my_count
       << " detected after "
       << sc_time_stamp() - t_start
       << endl;
}//end monitor_my_method()

#ifdef SYSTEMC_V2_1
void event_filled::monitor_better_method(void) {
  cout << "INFO: better_event " 
       << ++better_count
       << " detected after "
       << sc_time_stamp() - t_start
       << endl;
}//end monitor_better_method()
#endif

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: event_filled.cpp,v 1.3 2004/02/02 12:34:48 dcblack Exp $

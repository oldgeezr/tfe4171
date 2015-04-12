//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This example illustrates how to insert time delays into SC_METHODs.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iomanip>
#include "method_delay.h"

using std::cout;
using std::setw;
using std::endl;
using namespace sc_core; 
const sc_time FIVE(5,SC_NS);

void method_delay::delay_method(void) {
  switch (state) 
  {
    case INIT:
      cout << setw(5) << sc_time_stamp() << " Initializing" << endl;
      cout << "      Preparing to wait 5 nsec(FIVE)" << endl;
      state = FIVE_1;
      next_trigger(FIVE);
      break;
    case FIVE_1:
      cout << setw(5) << sc_time_stamp() << " Delayed five" << endl;
      state = FIVE_2;
      cout << "      Preparing to wait 5 nsec(FIVE)" << endl;
      next_trigger(FIVE);
      break;
    case FIVE_2:
      cout << setw(5) << sc_time_stamp() << " Delayed five" << endl;
      cout << "      Preparing to wait zero" << endl;
      state = ZERO_1;
      next_trigger(SC_ZERO_TIME);
      break;
    case ZERO_1:
      cout << setw(5) << sc_time_stamp() << " Delayed one delta cycle" << endl;
      cout << "      Preparing to wait zero" << endl;
      state = ZERO_2;
      next_trigger(SC_ZERO_TIME);
      break;
    case ZERO_2:
      cout << setw(5) << sc_time_stamp() << " Delayed one delta cycle" << endl;
      cout << "      Preparing to stop after 5 nsec(FIVE)" << endl;
      state = STOP;
      next_trigger(FIVE);
      break;
    case STOP:
      cout << setw(5) << sc_time_stamp() << " Stopping" << endl;
      next_trigger(99*FIVE);
      sc_stop();
      break;
  }
}
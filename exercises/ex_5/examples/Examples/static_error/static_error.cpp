//BEGIN static_error.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   Static sensitivity lists are confusing. This code example
//   illustrates common errors.
//

#include "static_error.h"

void static_error::nonsense_thread(void) {
  for(;;) {
    wait();
    std::cout << "INFO @" << sc_time_stamp() << " "
              << "Did wait()" << std::endl;
  #ifdef E3
    wait(sigval_pi->posedge());            // Compile ERROR (bool is not event)
    std::cout << "INFO @" << sc_time_stamp() << " "
              << "Did wait(sigval_pi->posedge())" << std::endl; // NEVER get this
  #endif
    wait(sigfnd_pi.pos());                 // event_finder is allowed in wait()
    std::cout << "INFO @" << sc_time_stamp() << " "
              << "Did wait(sigfnd_pi.pos())" << std::endl;
    wait(sigevt_pi->posedge_event());      // OK
    std::cout << "INFO @" << sc_time_stamp() << " "
              << "Did wait(sigevt_pi->posedge_event())" << std::endl;
    if (sigval_pi->posedge()) {            // OK
      std::cout << "INFO @" << sc_time_stamp() << " "
                << "Did if(posedge())" << std::endl;
    }//endif
    wait(global_event);
      std::cout << "INFO @" << sc_time_stamp() << " "
                << "Did wait(global_event)" << std::endl;
  }//endforever
}//end static_error::nonsense_thread()

void static_error::global_thread(void) {
  const sc_time t_11NS(11,SC_NS);
  wait(t_11NS);
  std::cout << "INFO @" << sc_time_stamp()
            << "Did global_event.notify()" << std::endl;
  global_event.notify();
}//end static_error::global_thread()

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END static_error.cpp

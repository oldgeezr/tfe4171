#ifndef STATIC_ERROR_H
#define STATIC_ERROR_H
//BEGIN static_error.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   Static sensitivity lists are confusing. This code example
//   illustrates common errors.
//
// EXPLANATION
//   The typical error message when the sensitive arguments are 
//   incorrect is:
//
//     Error: (E112) get interface failed: port is  
//     not bound: port 'nerves_i.port_1' (sc_port)
//   
//   This is precisely because the sensitive statement executes
//   before port binding has been completed.
//
// SYNTAX
//   make static_error; # runs without errors
//   make E1;           # runs with error #1 (elaboration error)
//   make E2;           # runs with error #2 (compile time)
//   make E3;           # runs with error #3
//
// DESIGN HIERARCHY
//   sc_main()
//    +- sc_signal<bool> sigevt
//    +- sc_signal<bool> sigval
//    +- static_error    disconnect_i
//       +- SC_THREAD    nonsense_thread << sigfnd_pi << sigevt_pi << sigval_pi
//       +- SC_THREAD    global_thread
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>

extern sc_event global_event;

SC_MODULE(static_error) {
  sc_in<bool >                    sigfnd_pi;
  sc_port<sc_signal_in_if<bool> > sigevt_pi; // Won't bind because of ERROR
  sc_port<sc_signal_in_if<bool> > sigval_pi; // Won't bind because of ERROR

  SC_CTOR(static_error) {
    SC_THREAD(nonsense_thread);
    sensitive << sigfnd_pi.pos();            // OK
  #ifdef E1
    sensitive << sigevt_pi->posedge_event(); // Elaborate ERROR (event is not event_finder)
  #endif
  #ifdef E2
    sensitive << sigval_pi->posedge();       // Compile ERROR (bool is not event_finder)
  #endif
    SC_THREAD(global_thread);
  }//end SC_CTOR

  void nonsense_thread(void);
  void global_thread(void);

};//end SC_MODULE(static_error)

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: static_error.h,v 1.3 2004/04/15 17:45:05 dcblack Exp $

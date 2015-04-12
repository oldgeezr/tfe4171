#ifndef M3_H
#define M3_H
//BEGIN connections.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>
#include <interfaces.h>

SC_MODULE(m3) {
  // Ports
  sc_port<if5> pJ;
  SC_CTOR(m3)
  : pJ("pJ")  // label the port to aid debug
  {
    // Local processes
    SC_THREAD(m3_thread);
  }
  void m3_thread(void) {
  }
};
#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: m3.h,v 1.3 2004/04/15 17:37:49 dcblack Exp $

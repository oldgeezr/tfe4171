#ifndef M2_H
#define M2_H
//BEGIN connections.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>
#include <interfaces.h>

SC_MODULE(m2) {
  // Ports
  sc_port<ifD,2> pD;
  sc_port<if3>   pE;
  sc_port<ifF>   pF;
  SC_CTOR(m2)
  : pD("pD"), // label all the ports to aid debug
    pE("pE"),
    pF("pF")
  {
    SC_THREAD(m2_thread);
  }
  void m2_thread(void) {
  }
};
#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: m2.h,v 1.3 2004/04/15 17:37:44 dcblack Exp $

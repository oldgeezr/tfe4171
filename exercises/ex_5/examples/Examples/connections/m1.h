#ifndef M1_H
#define M1_H
//BEGIN connections.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>
#include <interfaces.h>

SC_MODULE(m1), public ifW {
  // Ports
  sc_port<if1> pA;
  sc_port<ifB> pB;
  sc_port<ifD> pC;
#ifdef SYSTEMC_V2_1
  sc_export<if6> pG;
#endif
  // Interface ifW
  #include "interfaces.inc"
  // Local channels for sc_exports
  chC cCi;
  chG cGi;
  SC_CTOR(m1)
  : pA("pA"), // label all the ports & channels to aid debug
    pB("pB"),
    pC("pC"),
#ifdef SYSTEMC_V2_1
    pG("pG"),
#endif
    cCi("cCi"),
    cGi("cGi")
  {
    // Connectivity
    pC(cCi);
#ifdef SYSTEMC_V2_1
    pG(cGi);
#endif
    // Local processes
    SC_THREAD(m1_thread);
  }
  void m1_thread(void) {
  }
};
#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: m1.h,v 1.5 2004/04/15 17:37:38 dcblack Exp $

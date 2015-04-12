#ifndef M1_H
#define M1_H
//BEGIN connections.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>
#include <interfaces.h>

SC_MODULE(m1)
, public ifW  // inherit from ifW, in addition to sc_module in SC_MODULE macro
{
  // Ports
  sc_port<if1> pA;
  sc_port<ifB> pB;
  sc_port<ifD> pC;
  sc_export<if6> pG;
  
  // Interface ifW
  #include "interfaces.inc"
  
  // Local channels for sc_exports
  chC cCi;
  chG cGi;
  
  // Constructor
  SC_CTOR(m1)
  : pA("pA"), // label all the ports & channels to aid debug
    pB("pB"),
    pC("pC"),
    pG("pG"),
    cCi("cCi"),
    cGi("cGi")
  {
    // Connectivity
    pC(cCi);
    pG(cGi);
    // Local processes
    SC_THREAD(m1_thread);
  }
  
  void m1_thread(void) {/*empty*/}
};
#endif

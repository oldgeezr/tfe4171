#ifndef M2_H
#define M2_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>
#include <interfaces.h>

SC_MODULE(m2) {
  // Ports
  sc_port<ifD,2> pD;
  sc_port<if3>   pE;
  sc_port<ifF>   pF;
  
  // Constructor
  SC_CTOR(m2)
  : pD("pD"), // label all the ports to aid debug
    pE("pE"),
    pF("pF")
  {
    SC_THREAD(m2_thread);
  }
  
  void m2_thread(void) {/*empty*/}
};
#endif
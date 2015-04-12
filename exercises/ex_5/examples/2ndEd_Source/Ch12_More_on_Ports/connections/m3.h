#ifndef M3_H
#define M3_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>
#include <interfaces.h>

SC_MODULE(m3) {
  // Ports
  sc_port<if5> pJ;
  
  // Constructor
  SC_CTOR(m3)
  : pJ("pJ")  // label the port to aid debug
  {
    // Local processes
    SC_THREAD(m3_thread);
  }
  
  void m3_thread(void) 
  {/*empty*/}
};
#endif

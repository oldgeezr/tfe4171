#ifndef STIM_H
#define STIM_H
//BEGIN stim.h (systemc)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


#include <systemc.h>

SC_MODULE(stim) {
  // Ports
  sc_out<sc_uint<8> > DIN;
  sc_out<bool>        WRB, RDB;
  sc_in<sc_uint<8> >  DOUT;
  sc_out<sc_uint<3> > ADR;
  // Constructor
  SC_CTOR(stim) {
    // Register processes
    SC_THREAD(stim_thread);
  }
  // Declare processes
  void stim_thread(void);
  // Support methods
  void read(sc_uint<3> addr);
  void write(sc_uint<3> addr, sc_uint<8> data);
};//end SC_MODULE(stim)

#endif

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// END $Id: stim.h,v 1.3 2004/04/15 17:37:14 dcblack Exp $

#ifndef RAM8X8_H
#define RAM8X8_H
//BEGIN ram8x8.h (systemc)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>

SC_MODULE (ram8x8) {
  // Ports
  sc_in<sc_uint<8> >  DIN;
  sc_in<bool>         WRB, RDB;
  sc_out<sc_uint<8> > DOUT;
  sc_in<sc_uint<3> >  ADR;
  
  // Local data
  sc_uint<8> MEM_ARRAY[8];

  // Constructor
  SC_CTOR(ram8x8) {
    // Register processes
    SC_METHOD(ram_method);
      sensitive << DIN << WRB << RDB << ADR;
  }
  // Processes
  void ram_method(void);
  // Support methods

};//end SC_MODULE(ram8x8)

#endif

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// END $Id: ram8x8.h,v 1.3 2004/04/15 17:37:08 dcblack Exp $

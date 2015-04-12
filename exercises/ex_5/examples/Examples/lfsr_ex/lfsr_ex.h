#ifndef LFSR_EX_H
#define LFSR_EX_H
//BEGIN lfsr_ex.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   TO_BE_SUPPLIED
//
// DESIGN HIERARCHY
//   sc_main()
//   +- lfsr_ex_i
//    +- lfsr_ex_PROCESS
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>

SC_MODULE(lfsr_ex) {
  // Ports
  sc_in<bool> sample;
  sc_out<sc_uint<32> > signature;
  sc_in<bool> clock;
  sc_in<bool> reset;
  // Constructor
  SC_CTOR(lfsr_ex) {
    // Register process(es)
    SC_METHOD(lfsr_ex_method);
    sensitive << clock.pos() << reset;
    signature.initialize(0);
  }
  // Declare process(es)
  void lfsr_ex_method();
private:
  // Local data
  sc_uint<32> LFSR_reg;
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: lfsr_ex.h,v 1.3 2004/04/15 17:41:35 dcblack Exp $

//BEGIN stim.h (systemc)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <stim.h>

void stim::stim_thread(void) {
  RDB->write(false);
  WRB->write(false);
  wait(SC_ZERO_TIME);
  for (unsigned a=0;a!=8;a++) {
    write(a,a<<3+a);
    read(a);
  }//endfor
  for (unsigned i=0;i!=20;i++) {
    bool wrb = (rand()&1) == 1;
    sc_uint<3> a = rand()&7U;
    if (wrb == true) {
      sc_uint<8> d = rand()&255U;
      write(a,d);
      read(a);
    } else {
      read(a);
    }//endif
  }//endfor
}//end stim::stim_thread

void stim::read(sc_uint<3> addr) {
  ADR->write(addr);
  RDB->write(true);
  wait(SC_ZERO_TIME); // allow address write
  wait(SC_ZERO_TIME); // allow response
  sc_uint<8> data = DOUT->read();
  cout << "Read from address 0x" << ADR->read()
       << " returned 0x" << hex << data << endl;
  RDB->write(false);
}//end stim::read

void stim::write(sc_uint<3> addr, sc_uint<8> data) {
  ADR->write(addr);
  DIN->write(data);
  WRB->write(true);
  wait(SC_ZERO_TIME);
  cout << "Wrote to  address 0x" << hex << ADR->read()
       << " with value 0x" << hex << DIN->read() << endl;
  WRB->write(false);
}//end stim::write

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// END $Id: stim.cpp,v 1.2 2004/02/02 12:08:16 dcblack Exp $

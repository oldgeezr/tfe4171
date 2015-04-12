//BEGIN device.cpp (systemc)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See varports.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "device.h"


void device::rcv_thread() {
  int din;
  for(;;) {
    din = rcv_p->read();
  }//endfor i
}//end device::rcv_thread

void device::xmt_thread() {
  for(;;) {
    // Generate random data with random time delay
    int delay = abs(15 + rand()%15);
    int dout = rand();
    sc_time now=sc_time_stamp();
    wait(delay,SC_NS);
    xmt_p->write(dout);
  }//endforever
}//end device::xmt_thread

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: device.cpp,v 1.1 2004/02/21 21:04:35 dcblack Exp $

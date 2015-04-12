#ifndef SNK_H
#define SNK_H
//BEGIN snk.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   See fifo_of_ptr.h


#include <systemc.h>
#include <cmath>
#include "mydata.h"

SC_MODULE(snk) {
  sc_fifo_in<mydata*> in;
  SC_CTOR(snk):count(0) {
    SC_METHOD(snk_method);
    sensitive << in.data_written();
    dont_initialize();
  }
  void snk_method(void);
  int count;
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: snk.h,v 1.3 2004/04/15 17:39:16 dcblack Exp $

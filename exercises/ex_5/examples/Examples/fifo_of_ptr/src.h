#ifndef SRC_H
#define SRC_H
//BEGIN src.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   See fifo_of_ptr.h


#include <systemc.h>
#include "mydata.h"

SC_MODULE(src) {
  sc_fifo_out<mydata*> out;
  SC_CTOR(src):count(0) {
    SC_THREAD(src_thread);
  }
  void src_thread(void);
  unsigned count;
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: src.h,v 1.3 2004/04/15 17:39:21 dcblack Exp $

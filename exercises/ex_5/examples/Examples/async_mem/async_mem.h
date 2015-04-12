#ifndef ASYNC_MEM_H
#define ASYNC_MEM_H
//BEGIN async_mem.h (systemc)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


#include <systemc.h>
#include "stim.h"
#include "ram8x8.h"

SC_MODULE(async_mem) {
  // Local channels
  sc_signal<sc_uint<3> > a;
  sc_signal<sc_uint<8> > din, dout;
  sc_signal<bool> rdb, wrb;
  // Local instances
  stim stim1;
  ram8x8 mem1;
  SC_CTOR(async_mem);
};

#endif

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// END $Id: async_mem.h,v 1.2 2004/04/15 17:37:04 dcblack Exp $

//BEGIN async_mem.cpp (systemc)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "async_mem.h"
async_mem::async_mem(sc_module_name nm)
: sc_module(nm),
  stim1("stim1"),
  mem1("mem1")
{
  // Connectivity
  stim1.ADR(a);
  stim1.DIN(din);
  stim1.DOUT(dout);
  stim1.RDB(rdb);
  stim1.WRB(wrb);
  mem1.ADR(a);
  mem1.DIN(din);
  mem1.DOUT(dout);
  mem1.RDB(rdb);
  mem1.WRB(wrb);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// END $Id: async_mem.cpp,v 1.1 2004/01/17 04:30:06 dcblack Exp $

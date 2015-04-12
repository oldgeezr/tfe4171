//BEGIN main.cpp (systemc)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "async_mem.h"

int sc_main(int argc, char* argv[]) {
  async_mem async_mem_i("async_mem_i");
  sc_start();
  return 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// END $Id: main.cpp,v 1.1 2004/01/17 04:30:06 dcblack Exp $

//BEGIN ram8x8.cpp (systemc)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "ram8x8.h"

void ram8x8::ram_method(void) {
  if (WRB->read() == 1)
    MEM_ARRAY[ADR->read()] = DIN->read();

  else if (RDB.read() == 1)
    DOUT->write(MEM_ARRAY[ADR->read()]);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// END $Id: ram8x8.cpp,v 1.2 2004/02/02 12:08:16 dcblack Exp $

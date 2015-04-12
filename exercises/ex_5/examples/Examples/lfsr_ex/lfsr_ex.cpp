//BEGIN lfsr_ex.cpp (systemc)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See lfsr_ex.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "lfsr_ex.h"

#include "lfsr_ex.h"
void lfsr_ex::lfsr_ex_method() {
  if (reset->read() == true) {
    LFSR_reg = 0;
    signature->write(LFSR_reg);
  } else {
    bool lsb = LFSR_reg[31] ^ LFSR_reg[25] ^ LFSR_reg[22] ^ LFSR_reg[21] 
             ^ LFSR_reg[15] ^ LFSR_reg[11] ^ LFSR_reg[10] ^ LFSR_reg[ 9] 
             ^ LFSR_reg[ 7] ^ LFSR_reg[ 6] ^ LFSR_reg[ 4] ^ LFSR_reg[ 3] 
             ^ LFSR_reg[ 1] ^ LFSR_reg[ 0] ^ sample->read();
    LFSR_reg.range(31,1) = LFSR_reg.range(30,0);
    LFSR_reg[0] = lsb;
    signature->write(LFSR_reg);
  }//endif
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: lfsr_ex.cpp,v 1.1 2004/02/02 12:46:14 dcblack Exp $

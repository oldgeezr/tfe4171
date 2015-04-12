//BEGIN src.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   See fifo_of_ptr.h

#include "src.h"
#include "defines.h"

void src::src_thread(void) {
  mydata* ptr;
  for (unsigned i=0;i!=SEND;i++) {
    count++;
    ptr = new mydata(i);
    do { ptr->rand(); } while (ptr->data() == STOP);
    std::cout
      << "S" << count << " "
      << "sending  " << ptr->data()
      << std::endl;
    out->write(ptr);
  }//endfor
  std::cout << "Sending STOP" << std::endl;
  ptr = new mydata(STOP);
  out->write(ptr);
  while (out->num_free() < DEPTH)
    wait(SC_ZERO_TIME);
}//end src_thread()

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: src.cpp,v 1.2 2004/02/02 12:37:18 dcblack Exp $

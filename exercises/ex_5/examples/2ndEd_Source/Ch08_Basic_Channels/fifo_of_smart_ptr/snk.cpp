//BEGIN snk.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   See fifo_of_ptr.h

#include "snk.h"
#include "defines.h"
using namespace sc_core;

void snk::snk_method(void) {
  boost::shared_ptr<mydata> ptr;
  while (in->nb_read(ptr)) {
    count++;
    if (ptr->data() == STOP) {
      std::cout
        << "DETECTED STOP"
        << std::endl;
      sc_stop();
    } else {
      std::cout
        << "R" << count << " "
        << "received " << ptr->data()
        << std::endl;
    }//endif
  }//endwhile
}//end snk_method()

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id$

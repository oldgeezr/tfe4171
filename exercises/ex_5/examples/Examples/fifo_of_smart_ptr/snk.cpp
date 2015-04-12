//BEGIN snk.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   See fifo_of_ptr.h

#include "snk.h"
#include "defines.h"

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
//END $Id: snk.cpp,v 1.2 2004/02/02 12:36:45 dcblack Exp $

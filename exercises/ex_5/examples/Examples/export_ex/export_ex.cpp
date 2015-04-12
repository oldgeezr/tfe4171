//BEGIN export_ex.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See export_ex.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "export_ex.h"

void export_ex::export_ex_thread(void) {
  //BODY_OF_thread
  for (int i=0;i!=10;i++) {
    cout << "INFO: " << name() << " @ " << sc_time_stamp() << " : "
         << "Pushing " << i << " onto FIFO" << endl;
    my_fifo.write(i);
    wait(1,SC_NS);
  }//endfor
}//end export_ex_thread()

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: export_ex.cpp,v 1.3 2004/02/15 11:22:37 dcblack Exp $

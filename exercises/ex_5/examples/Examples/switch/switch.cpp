//BEGIN switch.cpp (systemc)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See switch.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "switch.h"

void Switch::switch_thread(void) {
  // Initialize requests
  for (unsigned i=0;i!=request_op.size();i++) {
    request_op[i]->write(true);
  }//endfor
  // Startup after first port is activated
  wait(T1_ip[0]->data_written_event()
      |T1_ip[1]->data_written_event()
      |T1_ip[2]->data_written_event()
      |T1_ip[3]->data_written_event()
  );
  cout << "INFO(switch_thread): "
       << "Starting up at " << sc_time_stamp() 
       << endl;
  for (;;) {
    for (unsigned i=0;i!=T1_ip.size();i++) {
      int value;
      // Process each port...
      value = T1_ip[i]->read();
      cout << "INFO(switch_thread): "
           << "Read " << hex << value
           << " at " << sc_time_stamp() << endl;
    }//endfor
  }//endforever
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: switch.cpp,v 1.2 2004/02/02 12:46:14 dcblack Exp $

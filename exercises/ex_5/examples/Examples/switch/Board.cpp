//BEGIN Board.cpp (systemc)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See switch.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "Board.h"

void Board::bored_thread(void) {
  wait(SC_ZERO_TIME);
  // NOTE: Everything is a local channel...
  for (unsigned i=0;i!=9;i++) {
    int val;
    wait(1,SC_NS);
    val = rand();
    switch(request[i].read()?i:9-i) {
      case 0:
      case 7:
        cout << "INFO(bored_thread): "
             << "Writing " << hex << val 
             << " to t1A "
             << "at " << sc_time_stamp()
             << endl;
        t1A.write(val); break;
      case 1:
      case 6:
        cout << "INFO(bored_thread): "
             << "Writing " << hex << val 
             << " to t1B "
             << "at " << sc_time_stamp()
             << endl;
        t1B.write(val); break;
      case 2:
      case 5:
      case 9:
        cout << "INFO(bored_thread): "
             << "Writing " << hex << val 
             << " to t1C "
             << "at " << sc_time_stamp()
             << endl;
        t1C.write(val); break;
      case 3:
      case 4:
        cout << "INFO(bored_thread): "
             << "Writing " << hex << val 
             << " to t1D "
             << "at " << sc_time_stamp()
             << endl;
        t1D.write(val); break;
    }//endswitch
  }//endfor
}//end Board::bored_thread

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: Board.cpp,v 1.2 2004/02/02 12:46:14 dcblack Exp $

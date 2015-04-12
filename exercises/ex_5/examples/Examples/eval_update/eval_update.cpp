//BEGIN eval_update/eval_update.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See eval_update.h for a details.

#include "eval_update.h"

void Eval_Update::Q1_method(void) { 
  cout << "Writing Q1" << std::endl;
  Q1.write(D);
}//end Q1_method()

void Eval_Update::Q2_method(void) { 
  cout << "Writing Q2" << std::endl;
  Q2.write(Q1);
}//end Q2_method()

void Eval_Update::testbench_thread(void) {
  for (D=5;D!=0;D--) {
    wait(clock->posedge_event());
    cout << "TB "
         << sc_time_stamp()
         << "  D=" << D
         << " Q1=" << Q1.read()
         << " Q2=" << Q2.read()
         << std::endl;
  }//endfor
  wait(2.0,SC_NS);
  cout << "TB "
       << sc_time_stamp()
       << "Stopping" << endl;
  sc_stop();
}//end testbench_thread()

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: eval_update.cpp,v 1.2 2004/02/02 12:34:03 dcblack Exp $

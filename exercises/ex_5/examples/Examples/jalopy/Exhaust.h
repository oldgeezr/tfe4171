#ifndef EXHAUST_H
#define EXHAUST_H
//BEGIN Exhaust.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See jalopy.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>

SC_MODULE(Exhaust) {
  SC_CTOR(Exhaust) {
    cout << "INFO: Constructing instance " << name() << endl;
    SC_THREAD(Exhaust_thread);
  }//end Exhaust()
  void Exhaust_thread(void) {
    cout << "INFO: Ran Exhaust_thread inside instance " << name() << endl;
  }//end Exhaust_thread()
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: Exhaust.h,v 1.1 2004/01/12 03:34:15 dcblack Exp $

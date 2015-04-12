#ifndef WHEEL_H
#define WHEEL_H
//BEGIN Wheel.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See jalopy.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>

SC_MODULE(Wheel) {
  SC_CTOR(Wheel) {
    cout << "INFO: Constructing instance " << name() << endl;
    SC_THREAD(Wheel_thread);
  }//end Wheel constructor
  void Wheel_thread(void) {
    cout << "INFO: Ran Wheel_thread inside instance " << name() << endl;
  }//end Wheel_thread()
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: Wheel.h,v 1.1 2004/01/12 03:34:15 dcblack Exp $

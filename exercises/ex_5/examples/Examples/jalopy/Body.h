#ifndef BODY_H
#define BODY_H
//BEGIN Body.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See jalopy.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>
#include "Wheel.h"

SC_MODULE(Body) {
  // Sub-module instances
  Wheel Wheel_FR;
  Wheel Wheel_FL;
  Wheel Wheel_RR;
  Wheel Wheel_RL;
  // Constructor
  SC_CTOR(Body) :
    Wheel_FL("Wheel_FL"),
    Wheel_FR("Wheel_FR"),
    Wheel_RL("Wheel_RL"),
    Wheel_RR("Wheel_RR")
  {
    cout << "INFO: Constructing instance " << name() << endl;
    SC_THREAD(Body_thread);
  }//end Body_thread()
  // Processes
  void Body_thread(void) {
    cout << "INFO: Ran Body_thread inside instance " << name() << endl;
  }//end Body_thread
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: Body.h,v 1.1 2004/01/12 03:34:15 dcblack Exp $

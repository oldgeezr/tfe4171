#ifndef BODY_H
#define BODY_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See sedan.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>
#include "Wheel.h"

SC_MODULE(Body) 
{
  // Sub-module instances
  Wheel Wheel_FR;
  Wheel Wheel_FL;
  Wheel Wheel_RR;
  Wheel Wheel_RL;
  
  // Constructor
  SC_HAS_PROCESS(Body);
  Body(sc_module_name nm); 
  
  // Processes
  void Body_thread(void);
};

#endif

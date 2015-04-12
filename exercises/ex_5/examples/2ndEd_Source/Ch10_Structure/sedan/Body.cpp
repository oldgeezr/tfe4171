//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See sedan.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <systemc>
using namespace sc_core;
using std::cout;
using std::endl;
#include "Body.h"

// Constructor
Body::Body(sc_module_name nm)
: sc_module(nm),
  Wheel_FL("Wheel_FL"),
  Wheel_FR("Wheel_FR"),
  Wheel_RL("Wheel_RL"),
  Wheel_RR("Wheel_RR")
{
  cout << "INFO: Constructing instance " << name() << endl;
  SC_THREAD(Body_thread);
}//end Body()

void Body::Body_thread(void) 
{
  cout << "INFO: Ran Body_thread inside instance " << name() << endl;
}//end Body_thread
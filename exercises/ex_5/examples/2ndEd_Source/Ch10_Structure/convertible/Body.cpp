//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See convertible.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <systemc>
using namespace sc_core;
#include "Body.h"
using std::cout;
using std::endl;

// Constructor
Body::Body(sc_module_name nm)
: sc_module(nm)
{
  cout << "INFO: Constructing instance " << name() << endl;
  
  // Processes
  SC_THREAD(Body_thread);
  
  // Instances
  Wheel_FL = new Wheel("Wheel_FL");
  Wheel_FR = new Wheel("Wheel_FR");
  Wheel_RL = new Wheel("Wheel_RL");
  Wheel_RR = new Wheel("Wheel_RR");
}//end Body_thread()

void Body::Body_thread(void) 
{
  cout << "INFO: Ran Body_thread inside instance " << name() << endl;
} //end Body_thread()
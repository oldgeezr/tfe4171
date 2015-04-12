//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See sedan.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <systemc>
using namespace sc_core;
#include "Wheel.h"
using std::cout;
using std::endl;

// Constructor
Wheel::Wheel(sc_module_name nm)
: sc_module(nm)
{
  cout << "INFO: Constructing instance " << name() << endl;
  SC_THREAD(Wheel_thread);
}//end Wheel constructor

void Wheel::Wheel_thread(void) 
{
  cout << "INFO: Ran Wheel_thread inside instance " << name() << endl;
}//end Wheel_thread()
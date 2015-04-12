//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See sedan.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <systemc>
using namespace sc_core;
using std::cout;
using std::endl;
#include "Cylinder.h"

// Constructor
Cylinder::Cylinder(sc_module_name nm)
: sc_module(nm)
{
  cout << "INFO: Constructing instance " << name() << endl;
  SC_THREAD(Cylinder_thread);
} //end Cylinder constructor

void Cylinder::Cylinder_thread(void) 
{
  cout << "INFO: Ran Cylinder_thread inside instance " << name() << endl;
} //end Cylinder_thread()
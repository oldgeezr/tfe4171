//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See sedan.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <systemc>
using namespace sc_core;
using std::cout;
using std::endl;
#include "Engine.h"

// Constructor
Engine::Engine(sc_module_name nm)
: sc_module(nm),
  fuelmix_i("fuelmix_i"),
  exhaust_i("exhaust_i"),
  cyl_i1("cyl_i1"),
  cyl_i2("cyl_i2")
{
  cout << "INFO: Constructing instance " << name() << endl;
  SC_THREAD(Engine_thread);
} //end Engine constructor

void Engine::Engine_thread(void) 
{
  cout << "INFO: Ran Engine_thread inside instance " << name() << endl;
} //end Engine_thread()
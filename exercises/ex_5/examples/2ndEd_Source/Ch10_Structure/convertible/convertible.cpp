//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See convertible.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <systemc>
using namespace sc_core;
#include "convertible.h"
using std::cout;
using std::endl;

void convertible::convertible_thread(void) 
{
  cout << "INFO: Ran convertible_thread inside instance " << name() << endl;
} //end convertible_thread()
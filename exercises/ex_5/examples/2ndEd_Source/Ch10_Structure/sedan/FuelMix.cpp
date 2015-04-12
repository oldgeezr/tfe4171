//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See FuelMix.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <systemc>
using namespace sc_core;
using std::cout;
using std::endl;
#include "FuelMix.h"

SC_HAS_PROCESS(FuelMix);
// Constructor
FuelMix::FuelMix(sc_module_name nm)
: sc_module(nm)
{
  cout << "INFO: Constructing instance " << name() << endl;
  SC_THREAD(FuelMix_thread);
} //end FuelMix constructor

void FuelMix::FuelMix_thread(void) 
{
  cout << "INFO: Ran FuelMix_thread inside instance " << name() << endl;
}// end FuelMix_thread()
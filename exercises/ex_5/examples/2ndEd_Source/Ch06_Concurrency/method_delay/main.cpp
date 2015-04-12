//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This example illustrates how to insert time delays into SC_METHODs.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>
using namespace sc_core; 
#include "method_delay.h"
using namespace std;

int sc_main(int argc, char* argv[]) 
{
  cout << "Elaborating" << endl;
  method_delay delay_i("delay_i");
  
  cout << "Simulating" << endl;
  sc_start(6*FIVE);
  if (not sc_end_of_simulation_invoked()) sc_stop(); //< invoke end_of_simulation
  
  cout << "INFO: method_delay COMPLETED" << endl;
  return 0;
}

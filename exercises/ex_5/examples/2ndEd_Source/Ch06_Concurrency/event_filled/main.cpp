//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// See event_filled.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>
#include "event_filled.h"

int sc_main(int argc, char* argv[]) 
{
  event_filled event_filled_i("event_filled_i");
  
  std::cout << "Starting event_filled simulation" << std::endl;
  
  sc_start();
  if (not sc_end_of_simulation_invoked()) sc_stop(); //< invoke end_of_simulation
  
  std::cout << "Exiting event_filled simulation" << std::endl;
  
  return 0;
}

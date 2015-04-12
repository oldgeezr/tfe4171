#include <systemc>
#include "turn_of_events.h"

using namespace sc_core;

int sc_main(int argc, char* argv[]) 
{
  turn_of_events turn_of_events_i("turn_of_events_i");
  sc_start();
  if (not sc_end_of_simulation_invoked()) sc_stop(); //< invoke end_of_simulation
  
  std::cout << "Exiting turn of events simulation" << std::endl;
  return 0;
}

#include <systemc>
#include "next_trigger.h"

using namespace sc_core; 
using namespace std;

int sc_main(int argc,char *argv[]) 
{
  cout << "INFO: Elaborating (constructing/binding)" << std::endl;
  next_trigger_example my_example("my_example");
  
  cout << "INFO: Starting simulation." << std::endl;
  sc_start(1,SC_SEC); // Simulate for 1 second
  if (not sc_end_of_simulation_invoked()) sc_stop(); //< invoke end_of_simulation
  
  cout << "INFO: Stopped simulating at " << sc_time_stamp() << "." << std::endl;
  cout << "INFO: next_trigger COMPLETED" << endl;
  return 0;
}//end sc_main()

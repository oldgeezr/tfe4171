#include "basic_process_ex.h"
int sc_main(int argc, char* argv[]) 
{
  basic_process_ex my_instance("my_instance");
  sc_start();
  if (not sc_end_of_simulation_invoked()) sc_stop(); //< invoke end_of_simulation
  return 0;
}

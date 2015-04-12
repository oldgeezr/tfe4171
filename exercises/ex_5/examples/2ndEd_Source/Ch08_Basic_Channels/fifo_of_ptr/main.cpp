//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See fifo_of_ptr.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
using std::cout;
using std::endl;

#include <systemc>
#include "fifo_of_ptr.h"
using namespace sc_core;

unsigned errors = 0;
const char* simulation_name = "fifo_of_ptr";

int sc_main(int argc, char* argv[]) 
{
  // Process command-line arguments
  if (argc == 2) 
  {
    // Better be an integer...
    DEPTH = atoi(argv[1]);
  }//endif
  std::cout << "Using FIFO depth of " << DEPTH << std::endl;
  std::cout << "Sending " << SEND << " values" << std::endl;

  cout << "INFO: Elaborating "<< simulation_name << endl;
  sc_fifo<mydata*> myfifo(DEPTH);
  src src_i("src_i");
  src_i.out(myfifo);
  snk snk_i("snk_i");
  snk_i.in(myfifo);

  cout << "INFO: Simulating "<< simulation_name << endl;
  sc_start();
  if (not sc_end_of_simulation_invoked()) sc_stop(); //< invoke end_of_simulation
  
  cout << "INFO: Post-processing "<< simulation_name << endl;
  cout << "INFO: Simulation " << simulation_name
       << " " << (errors?"FAILED":"PASSED")
       << " with " << errors << " errors"
       << endl;
  return errors?1:0;
}

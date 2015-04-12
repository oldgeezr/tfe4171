//BEGIN main.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See fifo_of_smart_ptr.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
using std::cout;
using std::endl;

#include <systemc.h>
#include "fifo_of_smart_ptr.h"

unsigned errors = 0;
char* simulation_name = "fifo_of_smart_ptr";

int sc_main(int argc, char* argv[]) {
  // Process command-line arguments
  if (argc == 2) {
    // Better be an integer...
    DEPTH = atoi(argv[1]);
  }//endif
  std::cout << "Using FIFO depth of " << DEPTH << std::endl;
  std::cout << "Sending " << SEND << " values" << std::endl;

  cout << "INFO: Elaborating "<< simulation_name << endl;
  sc_fifo<boost::shared_ptr<mydata> > myfifo(DEPTH);
  src src_i("src_i");
  src_i.out(myfifo);
  snk snk_i("snk_i");
  snk_i.in(myfifo);

  cout << "INFO: Simulating "<< simulation_name << endl;
  sc_start();
  cout << "INFO: Post-processing "<< simulation_name << endl;
  cout << "INFO: Simulation " << simulation_name
       << " " << (errors?"FAILED":"PASSED")
       << " with " << errors << " errors"
       << endl;
  return errors?1:0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: main.cpp,v 1.1 2003/11/25 22:52:41 dcblack Exp $

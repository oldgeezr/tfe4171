//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See equalizer_ex.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <systemc>
using namespace sc_core;
using std::cout;
using std::endl;
#include "equalizer_ex.h"

void equalizer_ex::equalizer_thread(void) 
{
  for(;;) 
  { 
    double sample;
    double result;
    wait();
    raw_fifo_ip->nb_read(sample);
    // ...
    // process data
    // ...
    equalized_fifo_op->write(result);
  }//endforever
  
}
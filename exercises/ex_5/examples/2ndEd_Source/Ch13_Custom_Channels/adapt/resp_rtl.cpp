//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See resp_rtl.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <systemc>
using namespace sc_core;
using std::cout;
using std::endl;
#include "resp_rtl.h"

void resp_rtl::resp_method(void) 
{
  bool val = irq_ip->read();
  cout << "INFO: " << name()
       << " Port irq_ip is " << val
       << " Received event at " << sc_time_stamp() << endl;
} //end resp_rtl::resp_method
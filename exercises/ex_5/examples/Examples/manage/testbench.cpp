//BEGIN: testbench.cpp (systemc)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See hier_chan.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <systemc.h>
#include "testbench.h"

void testbench::test_thread() {
  unsigned long addr;
  long data;
  srand(0);
  cout << "INFO: "<< name() << " @ " << sc_time_stamp() << " Starting..." << endl;
  // Randomly read & write values;
  for (unsigned i=0;i!=m_tests;i++) {
    addr = m_min_addr + rand() % (m_max_addr - m_min_addr);
    if (rand()&1) {
      data = rand();
      mem->write(addr,data);
      cout << "INFO: " << name() << " @ " << sc_time_stamp() << " " << i << " : "
           << "write(" << addr << ", " << data << ")"
           << endl;
    } else {
      data = mem->read(addr);
      cout << "INFO: " << name() << " @ " << sc_time_stamp() << " " << i << " : "
           << "read(" << addr << ") = " << data << ")"
           << endl;
    }//endif
  }//endfor
  cout << "INFO: "<< name() << " @ " << sc_time_stamp() << " Finished!" << endl;
}//end testbench::test_thread()

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: testbench.cpp,v 1.1 2004/02/29 04:39:35 dcblack Exp $

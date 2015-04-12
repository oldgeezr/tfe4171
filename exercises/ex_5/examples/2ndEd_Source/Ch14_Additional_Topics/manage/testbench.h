#ifndef TESTBENCH_H
#define TESTBENCH_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See hier_chan.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "CPU_if.h"

SC_MODULE(testbench) 
{
  sc_port<CPU_if> mem;
  
  // Constructor
  SC_HAS_PROCESS(testbench);
  testbench(
    sc_module_name nm,
    unsigned long  min_addr,
    unsigned long  max_addr,
    unsigned       tests
  )
  : sc_module(nm)
  , m_min_addr(min_addr)
  , m_max_addr(max_addr)
  , m_tests(tests)
  {
    SC_THREAD(test_thread);
  }
  
  void test_thread();
  
private:
  unsigned long m_max_addr;
  unsigned long m_min_addr;
  unsigned      m_tests;
};

#endif
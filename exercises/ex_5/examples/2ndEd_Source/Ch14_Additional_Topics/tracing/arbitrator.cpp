#include <systemc>
#include <string>
#include "arbitrator.h"
#include <set>
extern std::set<std::string> trace_cfg;
extern sc_core::sc_trace_file* tf;

// Constructor
SC_HAS_PROCESS(arbitrator);
arbitrator::arbitrator( sc_core::sc_module_name nm
                      , sc_core::sc_clock& clock
                      ) 
: sc_module(nm)
, m_clock(clock)
{
  // Process registration
  SC_THREAD(arbitrator_thread);
  
  // other initialization
  if (trace_cfg.find(name())!=trace_cfg.end()) {
    std::cout << "INFO: -- Tracing '" << name() << "'" << std::endl;
    sc_trace(tf,request_ip,"request_ip");
    sc_trace(tf,grant_op,"grant_op");
  }//endif
}//endconstructor

// Processes
void arbitrator::arbitrator_thread() 
{ 
  // Initialization
  grant_op.write(false);
  wait(sc_core::SC_ZERO_TIME);
  for(;;) 
  {
    wait(request_ip->posedge_event());
    wait((abs(rand())&15)*m_clock.period());
    grant_op.write(true);
    wait(request_ip->negedge_event());
    wait(clock_ip->negedge_event());
    grant_op.write(false);
  }//endforever
}//endthread arbitrator::arbitrator_thread

// Portions COPYRIGHT (C) 2004-2009 ESLX Inc.------------------------ //
// Permission granted for anybody to use this template provided this  //
// acknowledgement of ESLX Inc. remains.                              //
//------------------------------------------------------------------- //
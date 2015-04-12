//FILE: arbitrator.cpp (systemc)
//# vim600:set sw=2 tw=0 fdm=marker:
 #include <systemc.h>
#include "arbitrator.h"
#include <set>
extern std::set<sc_string> trace_cfg;
extern sc_trace_file* tf;
SC_HAS_PROCESS(arbitrator);
arbitrator::arbitrator(sc_module_name nm,sc_clock& clock) //Constructor{{{
: sc_module(nm)
, m_clock(clock)
{
  // Process registration
  SC_THREAD(arbitrator_thread);
  // other initialization
  if (trace_cfg.find(name())!=trace_cfg.end()) {
    cout << "INFO: -- Tracing '" << name() << "'" << endl;
    sc_trace(tf,request_ip,"request_ip");
    sc_trace(tf,grant_op,"grant_op");
  }//endif
}//endconstructor }}}
// Processes
void arbitrator::arbitrator_thread() { //{{{
  // Initialization
  grant_op.write(false);
  wait(SC_ZERO_TIME);
  for(;;) {
    wait(request_ip->posedge_event());
    wait((abs(rand())&15)*m_clock.period());
    grant_op.write(true);
    wait(request_ip->negedge_event());
    wait(clock_ip->negedge_event());
    grant_op.write(false);
  }//endforever
}//endthread arbitrator::arbitrator_thread}}}
//Portions COPYRIGHT (C) 2004 Eklectic Ally, Inc.------------------{{{//
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//-----------------------------------------------------------------}}}//
//END $Id: arbitrator.cpp,v 1.1 2004/02/29 04:40:16 dcblack Exp $

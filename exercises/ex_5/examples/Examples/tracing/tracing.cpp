//FILE:tracing.cpp (systemc)
//# vim600:sw=2:tw=0:fdm=marker
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See tracing.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <systemc.h>
#include "tracing.h"
#include "counter.h"
#include "arbitrator.h"
#include <set>
extern std::set<sc_string> trace_cfg;
extern sc_trace_file* tf;
SC_HAS_PROCESS(tracing);
tracing::tracing(sc_module_name nm,sc_clock& clock) //Constructor{{{
: sc_module(nm)
{
  // Submodule allocation
  counter_i = new counter("counter_i");
  arbitrator_i = new arbitrator("arbitrator_i",clock);
  // Connectivity
  arbitrator_i->request_ip(request_sig);
  arbitrator_i->grant_op(grant_sig);
  arbitrator_i->clock_ip(clock_ip);
  counter_i->transact_ip(transact_sig);
  counter_i->addr_ip(addr_sig);
  counter_i->data_in_ip(data_snd_sig);
  counter_i->data_out_op(data_rcv_sig);
  // Process registration
  SC_THREAD(tracing_thread);
  if (trace_cfg.find(name())!=trace_cfg.end()) {
    cout << "INFO: -- Tracing '" << name() << "'" << endl;
    sc_trace(tf,transact_sig,"transact_sig");
    sc_trace(tf,addr_sig,    "addr_sig");
    sc_trace(tf,data_snd_sig,"data_snd_sig");
    sc_trace(tf,data_rcv_sig,"data_rcv_sig");
  }//endif
}//endconstructor }}}
// Processes
void tracing::tracing_thread() { //{{{
  // Initialization
  unsigned addr;
  int data;
  write(0x1234,0xDeadBeef);
  data = read(0x1234);
  for (unsigned i=0;i!=10;i++) {
    data = rand();
    addr = rand() & 0x7FF;
    write(addr,data);
    data = read(addr);
  }//endfor
  wait(clock_ip->posedge_event());
  sc_stop();
}//endthread tracing::tracing_thread}}}
void tracing::write(unsigned addr, int data) {//{{{
  cout << "INFO(" << name() << "): write(" << hex << addr << "," << data << ")" << " @ " << dec << sc_time_stamp() << endl;
  request_sig.write(false);
  wait(clock_ip->negedge_event());
  request_sig.write(true);
  if (grant_sig.read() == false) {
    wait(grant_sig.value_changed_event());
  } else {
    cout << "WARN: grant present before request!" << endl;
  }//endif
  addr_sig.write(addr);
  data_snd_sig.write(data);
  transact_sig.write(counter::WRITE);
  wait(clock_ip->posedge_event());
  transact_sig.write(counter::IDLE);
  request_sig.write(false);
  if (grant_sig.read() == true) {
    wait(grant_sig.value_changed_event());
  } else {
    cout << "WARN: grant gone before wait!" << endl;
  }//endif
}//end tracing::write}}}
int tracing::read(unsigned addr) {//{{{
  int data;
  wait(clock_ip->negedge_event());
  request_sig.write(true);
  if (grant_sig.read() == false) {
    wait(grant_sig.value_changed_event());
  } else {
    cout << "WARN: grant present before request!" << endl;
  }//endif
  addr_sig.write(addr);
  transact_sig.write(counter::READ);
  wait(clock_ip->posedge_event());
  data = data_rcv_sig.read();
  transact_sig.write(counter::IDLE);
  request_sig.write(false);
  if (grant_sig.read() == true) {
    wait(grant_sig.value_changed_event());
  } else {
    cout << "WARN: grant gone before wait!" << endl;
  }//endif
  cout << "INFO(" << name() << "): read(" << hex << addr << ") =>" << data << " @ " << dec << sc_time_stamp() << endl;
  return data;
}//end tracing::read}}}
//Portions COPYRIGHT (C) 2004 Eklectic Ally, Inc.------------------{{{//
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. <www.eklect.com> remains.   //
//-----------------------------------------------------------------}}}//
//END $Id: tracing.cpp,v 1.1 2004/02/29 04:40:16 dcblack Exp $

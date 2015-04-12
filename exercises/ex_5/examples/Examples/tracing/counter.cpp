//FILE: counter.cpp (systemc)
//# vim600:set sw=2 tw=0 fdm=marker:
 #include <systemc.h>
 #include "counter.h"
// Constructors
SC_HAS_PROCESS(counter);
counter::counter(sc_module_name nm) //{{{
: sc_module(nm)
{
  // Process registration
  SC_THREAD(counter_thread);
}//endconstructor }}}
// Processes
void counter::counter_thread() { //{{{
  // Initialization
  int data = 0;
  for(;;) {
    wait(transact_ip->value_changed_event());
    cout << "INFO(" << name() << "): ";
    switch (transact_ip->read()) {
    case WRITE:
      data = data_in_ip->read();
      cout << "write(" << addr_ip << "," << data << ") @ ";
      break;
    case READ:
      cout << "read(" << addr_ip << ") => " << data << " @ ";
      data_out_op->write(~data);
      data++;
      break;
    case IDLE:
      cout << "--idle-- @ ";
      break;
    default:
      cout << "ERROR: Unknown transaction " << transact_ip->read() << " @ ";
    }//endswitch
    cout << sc_time_stamp() << endl;
  }//endforever
}//endthread counter::counter_thread}}}
//Portions COPYRIGHT (C) 2004 Eklectic Ally, Inc.------------------{{{//
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//-----------------------------------------------------------------}}}//
//END $Id: counter.cpp,v 1.1 2004/02/29 04:40:16 dcblack Exp $

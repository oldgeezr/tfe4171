//FILE:simple_spawn.cpp (systemc)
//# vim600:sw=2:tw=0:fdm=marker
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See simple_spawn.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifdef SYSTEMC_V2_1
#define SC_INCLUDE_DYNAMIC_PROCESSES
#include <systemc.h>
#include "simple_spawn.h"
// Constructor
SC_HAS_PROCESS(simple_spawn);
simple_spawn::simple_spawn(sc_module_name nm) //{{{
: sc_module(nm)
{
  // Process registration
  SC_THREAD(main_thread);
  // other initialization
}//endconstructor }}}
// Processes
void spawned_thread() {// This will be spawned{{{
  cout << "INFO: spawned_thread " << sc_get_curr_process_handle()->name()
       << " @ " << sc_time_stamp() << endl;
  wait(7,SC_NS);
  cout << "INFO: Exiting"
       << " @ " << sc_time_stamp() << endl;
}//end spawned_thread}}}
void simple_spawn::main_thread() { //{{{
  wait(15,SC_NS);
  sc_spawn(sc_bind(&spawned_thread));
  cout << "INFO: main_thread " << name()
       << " @ " << sc_time_stamp() << endl;
  wait(15,SC_NS);
  cout << "INFO: main_thread stopping "
       << " @ " << sc_time_stamp() << endl;
}//endthread simple_spawn::main_thread}}}
#endif
//Portions COPYRIGHT (C) 2004 Eklectic Ally, Inc.------------------{{{//
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//-----------------------------------------------------------------}}}//
//END $Id: simple_spawn.cpp,v 1.4 2004/03/03 04:54:38 dcblack Exp $

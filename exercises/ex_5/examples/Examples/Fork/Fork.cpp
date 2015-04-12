//FILE:fork.cpp (systemc)
//# vim600:sw=2:tw=0:fdm=marker
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See Fork.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifdef SYSTEMC_V2_1
#define SC_INCLUDE_DYNAMIC_PROCESSES
#include <systemc.h>
#include "Fork.h"
#include "Auto.h"
// Constructor
Fork::Fork(sc_module_name nm) //{{{
: sc_module(nm)
{
  // Submodule allocation
  Auto_i = new Auto("Auto_i",18.5);
  // Connectivity
  Auto_i->wheel_lf_ip(wheel_lf);
  Auto_i->wheel_rt_ip(wheel_rt);
  // Process registration
  SC_THREAD(fork_thread);
}//endconstructor }}}
// Processes
void Fork::fork_thread() { //{{{
  bool lf_up, rt_up;
  cout << "INFO(fork_thread): forking" << endl;
  SC_FORK
    sc_spawn(&lf_up,sc_bind(&Fork::road_thread,this,sc_ref(wheel_lf)),"lf"),
    sc_spawn(&rt_up,sc_bind(&Fork::road_thread,this,sc_ref(wheel_rt)),"rt")
  SC_JOIN
  cout << "INFO(fork_thread): joining" << endl;
  cout << "INFO(fork_thread): Left  wheel is " << (lf_up?"up":"down") << endl;
  cout << "INFO(fork_thread): Right wheel is " << (lf_up?"up":"down") << endl;
}//endthread Fork::fork_thread}}}
bool Fork::road_thread(sc_fifo<double>& which) { //{{{
  cout << "INFO(road_thread): Spawning " << sc_get_curr_process_handle()->name()
       << " @ " << sc_time_stamp() << endl;
  double road;
  sc_time delay;
  for (unsigned i=0;i!=100;i++) {
    road = (rand()%200)/10.0-10.0;
    delay = sc_time((rand()%100)/10.0,SC_SEC);
    wait(delay);
    cout << "INFO(road_thread): " << sc_get_curr_process_handle()->name()
         << " applying elevation of " << road
         << " @ " << sc_time_stamp() << endl;
    which.write(road);
  }//endfor
  return (road > 0.0);
}//endthread }}}
#endif
//Portions COPYRIGHT (C) 2004 Eklectic Ally, Inc.------------------{{{//
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//-----------------------------------------------------------------}}}//
//END $Id: Fork.cpp,v 1.2 2004/03/03 04:53:10 dcblack Exp $

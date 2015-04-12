//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See Fork.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define SC_INCLUDE_DYNAMIC_PROCESSES
#include <systemc>
using namespace sc_core;
#include "Auto.h"
using std::cout;
using std::endl;	
// Constructor
Auto::Auto(sc_module_name nm, double base_length)
: sc_module(nm)
, m_base_length(base_length)
{
  // Process registration & launch alternative to SC_THREAD
  sc_spawn(sc_bind(&Auto::Auto_thread,this),"Auto_thread");
}//endconstructor 

// Processes
void Auto::Auto_thread() 
{
  const double PI = 2*atan2(1,0);
  const double RAD2DEG = 180/PI;
  double wheel_lf = 0.0;
  double wheel_rt = 0.0;
  for(;;) {
    wait(wheel_lf_ip->data_written_event()|wheel_rt_ip->data_written_event());
    // One the two reads will produce results
    wheel_lf_ip->nb_read(wheel_lf);
    wheel_rt_ip->nb_read(wheel_rt);
    double angle = RAD2DEG*atan2(wheel_lf+wheel_rt,m_base_length);
    cout << "INFO: Body tilt " << angle << " degrees"
         << " @ " << sc_time_stamp() << endl;
  }//endforever
  
}//endthread Auto::Auto_thread

// Portions COPYRIGHT (C) 2004-2009 ESLX Inc.------------------------ //
// Permission granted for anybody to use this template provided this  //
// acknowledgement of ESLX Inc. remains.                              //
//------------------------------------------------------------------- //
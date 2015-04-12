//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See video_mix.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
using std::cout;
using std::endl;

#include <systemc>
using namespace sc_core;
#include "video_mix.h"

unsigned errors = 0;
const char* simulation_name = "video_mix";
const char* simulation_vers = "$Id$";

int sc_main(int argc, char* argv[]) 
{

  sc_fifo<YCRCB_frame>  dvd_in_fifo;
  sc_fifo<MIXER_ctrl>  ctrl_in_fifo;
  sc_fifo<YCRCB_frame>  video_out_fifo;
  sc_fifo<MIXER_state> status_out_fifo;
  sc_fifo<RGB_frame> rgb_in_fifo;

  cout << "INFO: " << simulation_name << " " << simulation_vers << endl;
  cout << "INFO: Elaborating "<< simulation_name << endl;
  //sc_set_time_resolution(1,SC_PS);
  //sc_set_default_time_unit(1,SC_NS);
  video_mix video_mix_i("video_mix_i");
  video_mix_i.dvd_pi(dvd_in_fifo);
  video_mix_i.control(ctrl_in_fifo);
  video_mix_i.video_po(video_out_fifo);
  video_mix_i.status(status_out_fifo);
  video_mix_i.rgb_pi(rgb_in_fifo);

  cout << "INFO: Simulating "<< simulation_name << endl;
  sc_start();
  if (not sc_end_of_simulation_invoked()) sc_stop(); //< invoke end_of_simulation
  
  cout << "INFO: Post-processing "<< simulation_name << endl;
  cout << "INFO: Simulation " << simulation_name
       << " " << (errors?"FAILED":"PASSED")
       << " with " << errors << " errors"
       << endl;
  return errors?1:0;
}

// Portions COPYRIGHT (C) 2003-2009 ESLX Inc.------------------------ //
// Permission granted for anybody to use this example provided this   //
// acknowledgement of ESLX Inc. remains.                              //
//------------------------------------------------------------------- //

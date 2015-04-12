#ifndef VIDEO_MIX_H
#define VIDEO_MIX_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This example illustrates port connections.
//
//     VIDEO_Mixer
//     .dvd_pi
//     .video_po
//     .control
//     .status
//     Rgb2YCrCb
//     .rgb_pi
//     .ycrcb_po
//     YCRCB_Mixer
//     .K_pi
//     .a_pi
//     .b_pi
//     .y_po
//
// DESIGN HIERARCHY
//   sc_main()
//   +- video_mix_i
//      +- 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "VIDEO_data.h"
#include "YCRCB_Mixer.h"
#include "Rgb2YCrCb.h"
// Submodule class declarations
SC_MODULE(video_mix) 
{
  // ports
  sc_port<sc_fifo_in_if<YCRCB_frame> >  dvd_pi;
  sc_port<sc_fifo_in_if<MIXER_ctrl> >   control;
  sc_port<sc_fifo_out_if<YCRCB_frame> > video_po;
  sc_port<sc_fifo_out_if<MIXER_state> > status;
  sc_port<sc_fifo_in_if<RGB_frame> >    rgb_pi;
  
  // local instances
  Rgb2YCrCb   Rgb2YCrCb_i  ;
  YCRCB_Mixer YCRCB_Mixer_i;
  
  // local channels
  sc_fifo<YCRCB_frame> ycrcb_graphics;
  video_mix(sc_module_name nm);// Constructor
};
#endif
// Portions COPYRIGHT (C) 2004-2009 ESLX Inc.-------------------------//
// Permission granted for anybody to use this template provided this  //
// acknowledgement of ESKX Inc. remains.                              //
//------------------------------------------------------------------- //
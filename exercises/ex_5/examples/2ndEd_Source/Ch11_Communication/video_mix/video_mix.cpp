//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See video_mix.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <systemc>
using namespace sc_core;
#include "video_mix.h"
#include <stdint.h>

// Constructor
SC_HAS_PROCESS(video_mix);
video_mix::video_mix(sc_module_name nm) //{{{
: sc_module(nm)
, Rgb2YCrCb_i  ("Rgb2YCrCb_i")
, YCRCB_Mixer_i("YCRCB_Mixer_i")
{
  // Connect
  Rgb2YCrCb_i.rgb_pi(rgb_pi);
  Rgb2YCrCb_i.ycrcb_po(ycrcb_graphics);
  YCRCB_Mixer_i.K_pi(control);
  YCRCB_Mixer_i.a_pi(dvd_pi);
  YCRCB_Mixer_i.b_pi(ycrcb_graphics);
  YCRCB_Mixer_i.y_po(video_po);
  YCRCB_Mixer_i.y_status(status);
}//endconstructor }}}

// Processes
void Rgb2YCrCb::do_convert() 
{
  uint32_t r,g,b;
	uint32_t y,cr,cb;
	RGB_frame rgb;
	YCRCB_frame ycrcb;

  for(;;)
  {
    rgb = rgb_pi->read();
    r = rgb >> 16;
    g = (rgb & 0x0000ff00) >> 8;
    b = rgb & 0x000000ff;
    y = 16 + (65 * r + 129 * g + 25 * b) / 128;
    cb = 128 + (112 * b - 38 * r - 74 * g) / 256;
    cr = 128 + (112 * r - 94 * g - 18 * b) / 256;
    ycrcb = (y << 8) | cr | (cb >> 4);
    ycrcb_po->write(ycrcb);
  }
}

void YCRCB_Mixer::do_mix() 
{
	YCRCB_frame a,b,yout;
	float k;
	uint32_t y,ya,yb,cr,cb,cra,cba,crb,cbb;
	MIXER_state st;

	for(;;) 
  {
		a = a_pi->read();
		b = b_pi->read();
		k = K_pi->read();
		ya = a >> 8;
		cra = a & 0x000000f0;
		cba = (a & 0x0000000f) << 4;
		yb = b >> 8;
		crb = b & 0x000000f0;
		cbb = (b & 0x0000000f) << 4;
		y = uint32_t(k*ya + (1-k)*yb);
		cr = uint32_t(k*cra + (1-k)*crb);
		cb = uint32_t(k*cba + (1-k)*cbb);
		yout = (y << 8) | cr | (cb >> 4);
		y_po->write(yout);
		st = uint32_t(100*k);
		y_status->write(st);
	}
}

//Portions COPYRIGHT (C) 2004-2009 ESLX Inc.------------------------- //
// Permission granted for anybody to use this template provided this  //
// acknowledgement of ESLX Inc. remains.                              //
//------------------------------------------------------------------- //
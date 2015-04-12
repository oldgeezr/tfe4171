//FILE:wave.cpp (systemc)
//# vim600:sw=2:tw=0:fdm=marker
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See wave.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <systemc.h>
#include "wave.h"
// Constructor
SC_HAS_PROCESS(wave);
wave::wave(sc_module_name nm) //Constructor{{{
: sc_module(nm)
{
  // Process registration
  SC_THREAD(wave_thread);
  // temperature initialization
  tracefile = sc_create_vcd_trace_file("wave");
  sc_trace(tracefile,oscillate,"osc");
  sc_trace(tracefile,pressure,"pressure");
  sc_trace(tracefile,temperature,"temperature");
  sc_trace(tracefile,cylinder,"cylinder");
}//endconstructor }}}
wave::~wave() {
    sc_close_vcd_trace_file(tracefile);
    cout << "Created wave.vcd" << endl;
}
// Processes
void wave::wave_thread() { //{{{
  // Initialization
  sc_time DELAY(1,SC_NS);
  oscillate.write(false);
  pressure.write(0);
  cylinder = 1;
  temperature = 0.4;
  wait(DELAY);
  for(int i=0;i!=50;i++) {
    oscillate.write(~oscillate.read());
    pressure.write(pressure.read()+1);
    temperature -= 0.01;
    cylinder = cylinder%8+1;
    wait(DELAY);
  }//endfor
  temperature = 0;
  for(double r=0.0;r<=10;r+=0.1) {
    if (int(pressure.read()) & 1) oscillate.write(~oscillate.read());
    pressure.write(pressure.read()-1);
    temperature = sin(r);
    cylinder = cylinder%8+1;
    wait(DELAY);
  }//endfor
}//endthread wave::wave_thread}}}
//Portions COPYRIGHT (C) 2004 Eklectic Ally, Inc.------------------{{{//
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//-----------------------------------------------------------------}}}//
//END $Id: wave.cpp,v 1.1 2004/02/29 04:41:14 dcblack Exp $

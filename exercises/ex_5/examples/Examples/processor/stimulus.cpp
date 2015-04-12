//FILE:processor.cpp (systemc)
//# vim600:sw=2:tw=0:fdm=marker
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// This module simply loads the memory with a program.
//
// See processor.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <systemc.h>
#include "stimulus.h"
// Constructor
SC_HAS_PROCESS(stimulus);
stimulus::stimulus(sc_module_name nm) // Constructor {{{
: sc_module(nm)
{
  // Process registration
  SC_THREAD(stimulus_thread);
  SC_METHOD(monitor_method);
  sensitive << reset_p << abort_p;
}//endconstructor }}}
// Processes
void stimulus::stimulus_thread() { //{{{
  // Declare labels
  unsigned LOOP, END;
  for (int pass=1;pass<=2;pass++) {
    pc = RESET_ADDR;
    write_instr(LOAD_ACC,IMMED,5);
  LOOP = pc;
    write_instr(DECR);
    write_instr(HALT,IF_FAIL);
    write_instr(LOAD_BUFF,0,1024);
    write_instr(DECODE,0);
    write_instr(CONVOLVE,0);
    write_instr(SEARCH,0);
    write_instr(JUMP,IF_FAIL,LOOP);
    write_instr(ALERT,0xBEEF);
    write_instr(JUMP,ALWAYS,LOOP);
    for (pc=1024;pc!=2048;pc++) {
      bus_p->write(pc,0);
    }//endfor
  END = pc;
  }//endfor
  abort_p->write(false);
  reset_p->write(SC_LOGIC_Z);
  wait(5,SC_NS);
  // Assert reset briefly
  reset_p->write(SC_LOGIC_0);
  wait(30,SC_NS);
  reset_p->write(SC_LOGIC_Z);
  wait(80,SC_NS);
  // Assert abort briefly
  abort_p->write(true);
  wait(20,SC_NS);
  abort_p->write(false);
}//endthread stimulus::stimulus_thread}}}
void stimulus::monitor_method() { //{{{
  if (reset_p->event()) {
    cout << sc_time_stamp() << " INFO: Detected reset=" << reset_p->read() << endl;
  }//endif
  if (abort_p->event()) {
    cout << sc_time_stamp() << " INFO: Detected abort=" << abort_p->read() << endl;
  }//endif
}//end stimulus::monitor_method }}}
void stimulus::write_instr( //{{{
  unsigned opcode, unsigned operand1, unsigned operand2
) {
  bus_p->write(pc++,opcode);
  switch (opcode) {
    // Two operands
    case LOAD_ACC:
    case STORE_BUFF:
    case LOAD_BUFF:
    case JUMP:
      bus_p->write(pc++,operand1);
      bus_p->write(pc++,operand2);
      break;
    // One operand
    case ALERT:
    case COMPARE:
    case CONVOLVE:
    case DECODE:
    case ENCODE:
    case HALT:
    case SEARCH:
    case STORE_ACC:
      bus_p->write(pc++,operand1);
      break;
    // No operands
    default:
    case NOP:
    case DECR:
    case INCR:
    case ABORT:
      break;
  }//endswitch
  return;
}//end stimulus::write_instr}}}
//Portions COPYRIGHT (C) 2004 Eklectic Ally, Inc.------------------{{{//
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//-----------------------------------------------------------------}}}//
//END $Id: stimulus.cpp,v 1.1 2004/02/22 19:50:51 dcblack Exp $

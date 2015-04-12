//FILE:processor.cpp (systemc)
//# vim600:sw=2:tw=0:fdm=marker
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See processor.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <systemc.h>
#include "processor.h"
extern unsigned errors;
// Constructor
SC_HAS_PROCESS(processor);
processor::processor(sc_module_name nm) // Constructor {{{
: sc_module(nm)
{
  // Process registration
  SC_CTHREAD(processor_cthread,clock_p.pos());
  watching(reset_p.delayed() == false);
}//endconstructor }}}
// Processes
void processor::processor_cthread() { //{{{
  // Initialization
  cout << sc_time_stamp() << " INFO: Initializing" << endl;
  pc = RESET_ADDR;
  result = true;
  for (int i=0;i!=1024;i++) {
    buff0[i] = 0.0;
    buff1[i] = 0.0;
    if (i != 1023) wait();
  }//endfor
  wait();
  for(;;) {
    W_BEGIN
      watching(abort_p.delayed() == true);
    W_DO
      read_instr();
      cout << sc_time_stamp() 
           << "INFO: "
           << disasm(pc,opcode,operand1,operand2)
           << endl;
      switch(opcode) {
        case HALT:
          switch (operand1) {
            case ALWAYS:
              cout << "INFO: Halting" << endl;
              sc_stop();
              break;
            case IF_PASS:
              if (result == true) {
                cout << "INFO: Halting" << endl;
                sc_stop();
              }//endif
              break;
            case IF_FAIL:
              if (result == false) {
                cout << "INFO: Halting" << endl;
                sc_stop();
              }//endif
              break;
          }//endswitch
          break;
        case LOAD_ACC:
          switch (operand1) {
            case IMMED: acc = operand2; break;
            case INDIR: acc = bus_p->read(operand2); break;
          }//endswitch
          break;
        case STORE_ACC:
          bus_p->write(operand1,acc);
          break;
        case INCR:
          acc++;
          result = (acc != 0);
          break;
        case DECR:
          acc--;
          result = (acc != 0);
          break;
        case LOAD_BUFF:
          for (int i=0;i!=1024;i++) {
            if (operand1 == 0) {
              buff0[i] = read_data(operand2+i);
            } else {
              buff1[i] = read_data(operand2+i);
            }//endif
            if (i != 1023) wait();
          }//endfor
          break;
        case STORE_BUFF:
          for (int i=0;i!=1024;i++) {
            if (operand1 == 0) {
               write_data(operand2+i,buff0[i]);
            } else {
               write_data(operand2+i,buff1[i]);
            }//endif
          }//endfor
          break;
        case JUMP:
          switch (operand1) {
            case ALWAYS: pc = operand2; break;
            case IF_PASS: if (result == true) pc = operand2; break;
            case IF_FAIL: if (result == false) pc = operand2; break;
            default: break; // NOP
          }//endswitch
          break;
        case ENCODE: 
          cout << "WARN: Compress not yet implemented" << endl;
          wait(30);
          result = true;
          break;
        case DECODE:
          cout << "WARN: Expand not yet implemented" << endl;
          wait(30);
          result = true;
          break;
        case CONVOLVE:
          cout << "WARN: Convolve not yet implemented" << endl;
          wait(30);
          result = true;
          break;
        case SEARCH:
          cout << "WARN: Search not yet implemented" << endl;
          wait(30);
          result = true;
          break;
        case COMPARE:
          cout << "WARN: Compare not yet implemented" << endl;
          wait(30);
          result = true;
          break;
        case ALERT:
          bus_p->write(ALERT_ADDR,operand1);
          break;
        default:
          cout << sc_time_stamp() << " ERROR: Unimplemented instruction -- resetting" << endl;
          errors++;
        case ABORT:
          reset_p->write(SC_LOGIC_0);// soft reset
          wait();
          reset_p->write(SC_LOGIC_Z);
          break;
      }//endswitch
      wait();
    W_ESCAPE
      cout << sc_time_stamp() << " WARN: Aborting" << endl;
    W_END
  }//endforever
}//endcthread }}}
void processor::read_instr() { //{{{
  opcode = bus_p->read(pc++);
  wait();
  switch (opcode) {
    // No operands
    default:
    case NOP:
    case INCR:
    case DECR:
    case ABORT:
      operand1 = 0;
      operand2 = 0;
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
      operand1 = bus_p->read(pc++);
      operand2 = 0;
      wait();
      break;
    // Two operands
    case JUMP:
    case LOAD_ACC:
    case LOAD_BUFF:
    case STORE_BUFF:
      operand1 = bus_p->read(pc++);
      wait();
      operand2 = bus_p->read(pc++);
      wait();
      break;
  }//endswitch
  return;
}//end processor::read_instr }}}
#define FRAC (1.0*(1<<31))
double processor::read_data(unsigned addr) { //{{{
  int upper = bus_p->read(addr);
  wait();
  unsigned lower = bus_p->read(addr+1);
  return double(upper+lower/FRAC);
}//end processor::read_data }}}
void processor::write_data(unsigned addr,double value) { //{{{
  int upper = int(value);
  unsigned lower = int(FRAC*(value - upper));
  bus_p->write(addr,upper);
  bus_p->write(addr+1,lower);
}//end processor::write_data }}}
//Portions COPYRIGHT (C) 2004 Eklectic Ally, Inc.------------------{{{//
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//-----------------------------------------------------------------}}}//
//END $Id: processor.cpp,v 1.1 2004/02/22 19:50:51 dcblack Exp $

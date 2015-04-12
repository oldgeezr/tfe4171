#ifndef PROCESSOR_H
#define PROCESSOR_H
//FILE: processor.h (systemc)
//# vim600:sw=2:tw=0:fdm=marker
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This is an example of a simple processor using clocked threads
//   (SC_CTHREAD) and watching constructs. This example uses elements
//   from other examples such as an event only clock (ea_heartbeat), a
//   pullup resolved channel (ea_pullup), a custom port (ea_heartport),
//   and a custom primitive channel (mem_arch). This example represents
//   a custom processor as might be used to manage operations on a
//   collision avoidance radar unit. No emphasis on performance has been
//   made.
//
// DESIGN HIERARCHY
//   sc_main()
//   +- ea_heartbeat
//   +- ea_pullup
//   +- processor_i
//   |  +- processor_cthread
//   +- stimulus_i
//      +- stimulus_thread
//      +- monitor_method
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "opcodes.h"
#include "mem_arch.h"
#include "ea_heartport.h"
// Submodule class declarations
SC_MODULE(processor) {
  // Ports
  ea_heartport      clock_p;
  sc_inout_resolved reset_p;
  sc_in<bool>       abort_p;
  sc_port<bus_if>   bus_p;
  // Constructor declarations
  processor(sc_module_name nm);
  // Process declarations
  void processor_cthread();
  // Helper functions
  void   read_instr();
  double read_data(unsigned addr);
  void   write_data(unsigned addr,double value);
  // Local data
private:
  unsigned opcode, operand1, operand2, pc, acc;
  double   buff0[1024], buff1[1024];
  bool     result;
};
#endif
//Portions COPYRIGHT (C) 2004 Eklectic Ally, Inc.------------------{{{//
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//-----------------------------------------------------------------}}}//
//END $Id: processor.h,v 1.2 2004/04/15 17:43:54 dcblack Exp $

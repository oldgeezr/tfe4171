#ifndef FORK_H
#define FORK_H
//FILE: Fork.h (systemc)
//# vim600:sw=2:tw=0:fdm=marker
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   The example illustrates a simple fork/join behavior. This example
//   also illustrates arguments by reference and return values.
//
// DESIGN HIERARCHY
//   sc_main()                        (road_thread)
//   +- fork_i                             v
//      +- fork_thread                 +--------+
//      |  *- road_thread(LF)          | Auto_i |
//      |  *- road_thread(RT)          +--------+
//      +- Auto_i                          ^       
//         +- Auto_thread             (road_thread)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <string>
// Submodule class declarations
struct Auto;
// Module definition
SC_MODULE(Fork) {
  // Local channel & submodule declarations
  Auto* Auto_i;
  sc_fifo<double> wheel_lf;
  sc_fifo<double> wheel_rt;
  // Constructor declarations
  SC_HAS_PROCESS(Fork);
  Fork(sc_module_name nm);
  // Process declarations
  void fork_thread();
  bool road_thread(sc_fifo<double>& which);
};
#endif
//Portions COPYRIGHT (C) 2004 Eklectic Ally, Inc.------------------{{{//
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//-----------------------------------------------------------------}}}//
//END $Id: Fork.h,v 1.2 2004/04/15 17:36:08 dcblack Exp $

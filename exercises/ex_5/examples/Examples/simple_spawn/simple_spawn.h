#ifndef SIMPLE_SPAWN_H
#define SIMPLE_SPAWN_H
//FILE: simple_spawn.h (systemc)
//# vim600:sw=2:tw=0:fdm=marker
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This example shows how a simple function may be dynamically
//   spawned as an SC_THREAD with a minimum of syntax.
//
// DESIGN HIERARCHY
//   sc_main()
//   +- simple_spawn_i
//    +- main_thread
//       *- spawn_thread /* dynamic */
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Submodule class declarations
SC_MODULE(simple_spawn) {
  // Local channel & submodule declarations
  // Constructor declarations
  simple_spawn(sc_module_name nm);
  // Process declarations
  void main_thread();
};
#endif
//Portions COPYRIGHT (C) 2004 Eklectic Ally, Inc.------------------{{{//
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//-----------------------------------------------------------------}}}//
//END $Id: simple_spawn.h,v 1.2 2004/04/15 17:44:59 dcblack Exp $

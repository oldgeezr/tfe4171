//FILE: /*{MDLNAME}*/.cpp (systemc)
//# vim600:set sw=2 tw=0 fdm=marker:
#include <systemc.h>
#include "/*{MDLNAME}*/.h"
// Constructors
SC_HAS_PROCESS(/*{MDLNAME}*/);
/*{MDLNAME}*/::/*{MDLNAME}*/(sc_module_name nm)
: sc_module(nm)
, /*{SUBMODULE}*/_i("/*{SUBMODULE}*/_i")
{
  // Connectivity
  /*{SUBMODULE}*/_i./*{PIN_NAME}*/(/*{PORT_OR_CHAN}*/);
  // Process registration
  SC_THREAD(/*{THREAD_PROCESS_NAME}*/_thread);
  SC_METHOD(/*{METHOD_PROCESS_NAME}*/_method);
    sensitive << /*{EVENT}*/;
    dont_initialize();
  // other initialization
}
// Processes
void /*{MDLNAME}*/::/*{THREAD_PROCESS_NAME}*/_thread() {
  // Initialization
  for(;;) {
    // Actions
    wait(/*{EVENT_LIST_OR_TIME}*/);
  }//endforever
}
void /*{MDLNAME}*/::/*{METHOD_PROCESS_NAME}*/_method() {
  // Actions
  next_trigger(/*{EVENT_LIST_OR_TIME}*/);
}
//Portions COPYRIGHT (C) 2004 Eklectic Ally, Inc.------------------{{{//
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//-----------------------------------------------------------------}}}//
//END $Id: MDLNAME_direct_sep.cpp,v 1.2 2004/02/21 21:04:35 dcblack Exp $

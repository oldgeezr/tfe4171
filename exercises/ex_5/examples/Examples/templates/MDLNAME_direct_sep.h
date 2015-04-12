//FILE: /*{MDLNAME}*/.h (systemc)
//# vim600:set sw=2 tw=0 fdm=marker:
#ifndef /*{MDLNAME}*/_H
#define /*{MDLNAME}*/_H
#include "/*{SUBMODULE}*/.h"
SC_MODULE(/*{MDLNAME}*/) {
  // Ports
  sc_port</*{INTERFACE}*/> /*{PORTNAME}*/;
  // Local channels & submodules
  /*{SUBMODULE}*/ /*{SUBMODULE}*/_i;
  // Constructors
  /*{MDLNAME}*/(sc_module_name nm);
  // Processes
  void /*{THREAD_PROCESS_NAME}*/_thread();
  void /*{METHOD_PROCESS_NAME}*/_method();
private:
  // Local data members
  /*{TYPENAME}*/ m_/*{VARNAME}*/;
};
#endif
//Portions COPYRIGHT (C) 2004 Eklectic Ally, Inc.------------------{{{//
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//-----------------------------------------------------------------}}}//
//END $Id: MDLNAME_direct_sep.h,v 1.2 2004/02/21 21:04:35 dcblack Exp $

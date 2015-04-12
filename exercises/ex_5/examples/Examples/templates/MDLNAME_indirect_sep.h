//FILE: /*{MDLNAME}*/.h (systemc)
//# vim600:set sw=2 tw=0 fdm=marker:
#ifndef /*{MDLNAME}*/_H
#define /*{MDLNAME}*/_H
// Submodule class declarations
struct /*{SUBMODULE}*/;
// Module definition
SC_MODULE(/*{MDLNAME}*/) {
  // Ports
  sc_port</*{INTERFACE}*/> /*{PORTNAME}*/;
  // Local channel & submodule declarations
  /*{SUBMODULE}*/* /*{SUBMODULE}*/_i;
  // Constructor declarations
  /*{MDLNAME}*/(sc_module_name nm);
  // Processe declarations
  void /*{THREAD_PROCESS_NAME}*/_thread();
  void /*{THREAD_PROCESS_NAME}*/_method();
private:
  // Local data members
  /*{TYPENAME}*/ m_/*{VARNAME}*/;
};
#endif
//Portions COPYRIGHT (C) 2004 Eklectic Ally, Inc.------------------{{{//
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//-----------------------------------------------------------------}}}//
//END $Id: MDLNAME_indirect_sep.h,v 1.2 2004/02/21 21:04:35 dcblack Exp $

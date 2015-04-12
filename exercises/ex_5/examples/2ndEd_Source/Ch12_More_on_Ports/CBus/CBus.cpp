//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See CBus.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <systemc.h>
#include "CBus.h"
#include "North_bus.h"
#include "South_bus.h"
#include "Debug_bus.h"
#include "CBus_rtl.h"
// Constructor
CBus::CBus(sc_module_name nm): sc_module(nm) 
{
  // Local instances
  nbus_ci  = new North_bus("nbus_ci");
  sbus_ci  = new South_bus("sbus_ci");
  debug_ci = new Debug_bus("debug_ci");
  rtl_i    = new CBus_rtl("rtl_i");
  
  // Export connectivity
  north_p(nbus_ci);
  south_p(sbus_ci);
  
  // Implementation connectivity
  rtl_i.nbus_p(nbus_ci);
  rtl_i.sbus_p(sbus_ci);
  rtl_i.dbug_p(debug_ci);
}// endconstructor
// Portions COPYRIGHT (C) 2004-2009 ESLX Inc.------------------------ //
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//------------------------------------------------------------------- //
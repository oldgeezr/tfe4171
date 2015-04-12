//BEGIN adapt.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See adapt.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <systemc>
using namespace sc_core;
using std::cout;
using std::endl;
#include "adapt.h"
#include "stim.h"
//#include "resp.h"
//#include "ea_interrupt.h"
#include "resp_rtl.h"
#include "interrupt2sigbool.h"

// Constructor
adapt::adapt(sc_module_name nm) {
  stim_i = new stim("stim_i");
  //irq = new ea_interrupt();
  //resp_i = new resp("resp_i");
    irq = new interrupt2sigbool();
    resp_i = new resp_rtl("resp_i");
  stim_i->irq_op(*irq);
  resp_i->irq_ip(*irq);
}//end adapt::adapt

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id$

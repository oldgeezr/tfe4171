//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See interrupt.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <systemc>
using namespace sc_core;
using std::cout;
using std::endl;

#include "interrupt.h"
#include "stim.h"
#include "resp.h"
#include "ea_interrupt.h"

// Constructor
interrupt::interrupt(sc_module_name nm)
{
  irq = new ea_interrupt();
  stim_i = new stim("stim_i");
  resp_i = new resp("resp_i");
  stim_i->irq_op(*irq);
  resp_i->irq_ip(*irq);
} //end interrupt::interrupt
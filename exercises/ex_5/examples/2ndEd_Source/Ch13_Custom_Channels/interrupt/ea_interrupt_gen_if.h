#ifndef EA_INTERRUPT_GEN_IF_H
#define EA_INTERRUPT_GEN_IF_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This is a custom primitive channel that supports the notion of
//   sending events between modules. To send an event, simply invoke
//   notify with the appropriate arguments. The receiving modules should
//   wait on the default event.
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct ea_interrupt_gen_if
: public sc_interface 
{
  virtual void notify() = 0;
  virtual void notify(sc_time t) = 0;
};

#endif
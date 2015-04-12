#ifndef EA_INTERRUPT_EVT_IF_H
#define EA_INTERRUPT_EVT_IF_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This is a custom interface that supports the notion of
//   sending events between modules. To send an event, simply invoke
//   notify with the appropriate arguments. The receiving modules should
//   wait on the default event.
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct ea_interrupt_evt_if
: public sc_interface 
{
  virtual const sc_event& default_event() const = 0;
};

#endif
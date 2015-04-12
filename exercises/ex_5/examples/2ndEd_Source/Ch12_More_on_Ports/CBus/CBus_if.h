//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See CBus.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef CBUS_IF_H
#define CBUS_IF_H
// Notice that these interfaces have what appears to be a collision in
// semantics; however, because we use sc_export they can be kept separate.
// This cannot be accomplished with a simple hierarchical channel approach.
struct CBus_North_if
: public sc_interface 
{
  virtual void lock(unsigned addr)=0;
  virtual void unlock(unsigned addr)=0;
  virtual void write(unsigned long addr, long data)=0;
  virtual long read(unsigned long  addr)=0;
};

struct CBus_South_if
: public sc_interface 
{
  virtual void write(unsigned long addr, long data)=0;
  virtual long read(unsigned long  addr)=0;
  virtual void irq(unsigned long addr)=0;
};

#endif

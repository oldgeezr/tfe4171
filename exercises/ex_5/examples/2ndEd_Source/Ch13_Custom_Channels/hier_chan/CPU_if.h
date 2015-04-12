#ifndef CPU_IF_H
#define CPU_IF_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See hier_chan.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct CPU_if: public sc_interface 
{
  virtual void write(unsigned long addr, long data) =0;
  virtual long read(unsigned long  addr)            =0;
};

#endif
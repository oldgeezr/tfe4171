//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See CBus.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef SOUTH_BUS_H
#define SOUTH_BUS_H
#include "CBus_if.h"
struct South_Bus 
: public sc_interface
, public CBus_South_if  
{
  void write(unsigned long addr, long data);
  long read(unsigned long  addr);
  void irq(unsigned long addr);
};

#endif


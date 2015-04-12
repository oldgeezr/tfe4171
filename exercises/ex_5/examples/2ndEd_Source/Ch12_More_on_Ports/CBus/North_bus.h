//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See CBus.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef NORTH_BUS_H
#define NORTH_BUS_H
#include "CBus_if.h"
struct North_bus 
: public sc_interface
, public CBus_North_if  
{
  void lock(unsigned addr);
  void unlock(unsigned addr);
  void write(unsigned long addr, long data);
  long read(unsigned long  addr);
};

#endif



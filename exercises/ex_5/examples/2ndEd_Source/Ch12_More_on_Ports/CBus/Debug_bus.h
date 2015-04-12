//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See CBus.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef DEBUG_BUS_H
#define DEBUG_BUS_H
#include "CBus_Debug_if.h"
struct Debug_Bus 
: public sc_channel
, public CBus_Debug_if  
{
  void write(unsigned long probe, long data);
  long read(unsigned long  probe);
};

#endif


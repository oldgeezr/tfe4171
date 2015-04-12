#ifndef GENGHIS_OUT_IF_H
#define GENGHIS_OUT_IF_H
//BEGIN Genghis_out_if.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This is the Genghis Chan, custom primitive channel definition.
//   It supports a very basic interface.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>

class Genghis_out_if : public sc_interface {
public:
  virtual void put(const char ID,int val) = 0;
  virtual bool nb_put(const char ID, int  val) = 0;
  virtual bool empty(const char ID) = 0;
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: Genghis_out_if.h,v 1.2 2004/04/15 17:43:14 dcblack Exp $

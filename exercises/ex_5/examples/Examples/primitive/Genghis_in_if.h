#ifndef GENGHIS_IN_IF_H
#define GENGHIS_IN_IF_H
//BEGIN Genghis_in_if.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This is the Genghis Chan, custom primitive channel definition.
//   It supports a very basic interface.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>

class Genghis_in_if : public sc_interface {
public:
  virtual int get(const char ID) = 0;
  virtual bool nb_get(const char ID, int& val) = 0;
  virtual bool full(const char ID) = 0;
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: Genghis_in_if.h,v 1.2 2004/04/15 17:43:08 dcblack Exp $

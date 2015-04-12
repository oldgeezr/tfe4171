#ifndef GENGHIS_H
#define GENGHIS_H
//BEGIN Genghis.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This is the Genghis Chan, custom primitive channel definition.
//   It supports a very basic interface.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>
#include "Genghis_out_if.h"
#include "Genghis_in_if.h"

class Genghis
: public sc_prim_channel,
  public Genghis_out_if,
  public Genghis_in_if 
{
public:
  Genghis(); // Constructor
  void put(const char ID,int val);
  int  get(const char ID);
  bool nb_put(const char ID, int  val);
  inline bool empty(const char ID);
  bool nb_get(const char ID, int& val);
  inline bool full(const char ID);
  inline void checkid(const char ID);
private:
  char     m_id;     
  int      m_value;
  bool     m_valid;
  sc_event m_changed;
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: Genghis.h,v 1.2 2004/04/15 17:43:04 dcblack Exp $

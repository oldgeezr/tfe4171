#ifndef EXPORT_EX_H
#define EXPORT_EX_H
//BEGIN export_ex.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   TO_BE_SUPPLIED
//
// DESIGN HIERARCHY
//   sc_main()
//   +- export_ex_i
//    +- export_ex_thread
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>

SC_MODULE(export_ex) {
  sc_export<sc_fifo_out_if<int> > stim_oxp;
  sc_fifo<int> my_fifo;
  SC_CTOR(export_ex)
  {
    SC_THREAD(export_ex_thread);
    // Connect sc_export to fifo
    stim_oxp(my_fifo);
  }
  void export_ex_thread(void);
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: export_ex.h,v 1.4 2004/04/15 17:38:53 dcblack Exp $

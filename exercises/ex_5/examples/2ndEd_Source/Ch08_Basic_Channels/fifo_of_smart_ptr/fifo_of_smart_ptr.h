#ifndef fifo_of_ptr_H
#define fifo_of_ptr_H
//BEGIN fifo_of_smart_ptr.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This design illustrates using a FIFO of pointers to custom
//   data. It was inspired by a posting on systemc.org.
//
// DESIGN HIERARCHY
//   sc_main()
//   +- src src_i // generates ten random values
//    +- src_thread
//   +- snk snk_i << in.data_written
//   +- snk_i
//    +- snk_thread
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>
#include "defines.h"
#include "mydata.h"
#include "src.h"
#include "snk.h"

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id$

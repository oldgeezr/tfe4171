#ifndef VARPORTS_H
#define VARPORTS_H
//BEGIN varports.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This example illustrates several concepts. The primary focus of
//   the example is programmable structure. Secondary ideas include
//   gathering traffic statistics, and error management. Most of the
//   action occurs in main.cpp.
//
//   This design is conceptually something like a passive ethernet
//   hub. Anywhere from 0 to N "devices" may be hung off the main
//   design. Data received by the varports instance on port i is
//   transmitted to ports 0..(i-1),(i+1)..(N-1). FIFOs are used for
//   channels. The idea is to adjust the service frequency and
//   FIFO depths for the best cost/performance.
//
//   *varports_i
//   +------------------+                *device_i[0]
//   |                  |  sc_fifo<>(D)  +-------+
//   |             rcv_p|<<<<<<<<<<<<<<<<|xmt_p  |
//   |  ________   xmt_p|>>>>>>>>>>>>>>>>|rcv_p  |
//   | |        |       |                +-------+
//   | |varports|       |           :        :
//   | |_thread |       |                *device_i[N-1]
//   | |________|       |                +-------+
//   |             rcv_p|<<<<<<<<<<<<<<<<|xmt_p  |
//   |             xmt_p|>>>>>>>>>>>>>>>>|rcv_p  |
//   |                  |                +-------+
//   +------------------+ 
//
// DESIGN HIERARCHY
//   sc_main()
//   +- varports_i
//   |  +- varports_thread
//   +- device_i[0..N]
//      +- xmt_thread
//      +- rcv_thread
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>

SC_MODULE(varports) {
  sc_port<sc_fifo_in_if<int>,0>  rcv_p;
  sc_port<sc_fifo_out_if<int>,0> xmt_p;
  SC_HAS_PROCESS(varports);
  // Constructor
  varports
  ( sc_module_name nm
  , sc_time process_time
  , unsigned samples_per_pass
  , unsigned fifo_depth
  , unsigned total_samples_to_process
  )
  : sc_module(nm)
  , t_PROCESS(process_time)
  , m_samples_per_pass(samples_per_pass)
  , m_processed(0)
  , m_samples_left(total_samples_to_process)
  {
    SC_THREAD(varports_thread);
    stats = new unsigned[fifo_depth+1];
    for (unsigned i=0;i!=fifo_depth;i++) {
      stats[i] = 0;
    }//endfor
  }
  ~varports() {
    delete [] stats;
  }
  void varports_thread();
  unsigned*     stats;// buckets for queue sizes
  sc_time       t_PROCESS;
  unsigned      m_samples_per_pass;
  unsigned long m_processed;
  unsigned      m_samples_left;
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: varports.h,v 1.2 2004/04/15 17:45:51 dcblack Exp $

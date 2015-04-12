#ifndef MEM_H
#define MEM_H
//BEGIN mem.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This module is wrapper that allows selection between modeling
//   levels.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>
#include "mem_arch.h"
#include "cpu2pca.h"
#include "mem_bsyn.h"
#include "ea_heartbeat.h"
#include "CPU_if.h"

#include <map>
extern std::map<sc_string,sc_string> cfg;

SC_MODULE(mem) {
  sc_export<CPU_if> CPU_p;
  mem_arch*     mem_arch_i;
  mem_bsyn*     mem_bsyn_i;
  cpu2pca*      cpu2pca_i;
  ea_heartbeat*             clock;
  sc_signal<bool>           ld;
  sc_signal<bool>           rw;
  sc_signal<unsigned long>  a;
  sc_signal_rv<32>          d;
  SC_HAS_PROCESS(mem);
  explicit mem(sc_module_name nm,
               unsigned long ba, unsigned sz) 
  : sc_channel(nm)
  {
    if (cfg[name()] == "rtl") {
      cout << "WARN: " 
           << cfg[name()] << " not yet supported "
           << "-- using default" << endl;
    }
    if (cfg[name()] == "bsyn") {
      clock = new ea_heartbeat("clock",sc_time(10,SC_NS));
      mem_bsyn_i = new mem_bsyn("mem_bsyn_i",ba,sz);
      mem_bsyn_i->ld(ld);
      mem_bsyn_i->rw(rw);
      mem_bsyn_i->a(a);
      mem_bsyn_i->d(d);
      mem_bsyn_i->ck(*clock);
      cpu2pca_i = new cpu2pca("cpu2pca_i");
      cpu2pca_i->ld(ld);
      cpu2pca_i->rw(rw);
      cpu2pca_i->a(a);
      cpu2pca_i->d(d);
      cpu2pca_i->ck(*clock);
      CPU_p(*cpu2pca_i);
    } else {
      cout << "INFO: Using default (arch) model for " << name() << endl;
      mem_arch_i = new mem_arch("mem_arch_i",ba,sz);
      CPU_p(*mem_arch_i);
    }//endif
  }
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: mem.h,v 1.2 2004/04/15 17:42:13 dcblack Exp $

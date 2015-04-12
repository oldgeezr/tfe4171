#ifndef counter_H
#define counter_H
//FILE: counter.h (systemc)
//# vim600:set sw=2 tw=0 fdm=marker:
// Module definition
SC_MODULE(counter) {
  // Ports
  sc_in<sc_uint<2> >  transact_ip;
  sc_in<unsigned>    addr_ip;
  sc_in<int>         data_in_ip;
  sc_out<int>        data_out_op;
  // Constructor declarations
  counter(sc_module_name nm);
  // Processe declarations
  void counter_thread();
  enum transaction {IDLE, READ, WRITE};
};
#endif
//Portions COPYRIGHT (C) 2004 Eklectic Ally, Inc.------------------{{{//
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//-----------------------------------------------------------------}}}//
//END $Id: counter.h,v 1.2 2004/04/15 17:45:32 dcblack Exp $

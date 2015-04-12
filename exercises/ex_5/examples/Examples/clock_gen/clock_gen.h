#ifndef CLOCK_GEN_H
#define CLOCK_GEN_H
//BEGIN clock_gen.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This example illustrates two methods of generating a clock
//   in a submodule. First, is a method compatible with SystemC
//   v2.0.1 using a method that monitors changes in the clock
//   and writes the value to a port. Second is a method using an
//   sc_export to simply export the clock channel.
//
// DESIGN HIERARCHY
//   sc_main()
//   +- clock_gen_i
//   |  |
//   |  |  clk1
//   |  |    v
//   |  +- clk1_method() -- generates clk1_p
//   |       v   clk2
// ~~|~~~~~~~v~~~~~v~~
//   |     clk1    V
// ~~|~~~~~~~v~~~~~v~~
//   +- monitor_i
//      +- clk1_method() -- monitors clk1_p
//      +- clk2_method() -- monitors clk2_p
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>

SC_MODULE(clock_gen) {
  sc_port<sc_signal_out_if<bool> >  clk1_p;
  sc_export<sc_signal_in_if<bool> > clk2_p;//SystemC 2.1
  sc_clock clk1;
  sc_clock clk2;
  SC_CTOR(clock_gen)
  : clk1("clk1",4,SC_NS)
  , clk2("clk2",6,SC_NS)
  {
    SC_METHOD(clk1_method);
    sensitive << clk1;
    clk2_p(clk2);
  }
  void clk1_method() {
    clk1_p->write(clk1);
  }
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: clock_gen.h,v 1.2 2004/04/15 17:37:24 dcblack Exp $

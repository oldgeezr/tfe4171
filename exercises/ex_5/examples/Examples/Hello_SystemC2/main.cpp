//FILE:main.cpp

#include <Hello_SystemC.h>

int sc_main(int argc, char* argv[]) {

  const sc_time t_PERIOD(8,SC_NS);
  sc_trace_file * tf = sc_create_vcd_trace_file ("hello");

  sc_clock clk("clk",t_PERIOD);

  Hello_SystemC iHello_SystemC("iHello_SystemC");

  iHello_SystemC.clk_pi(clk);

  sc_trace (tf, clk, "clk");
  sc_trace (tf, iHello_SystemC.clk_pi, "clk.pi");

  sc_start(sc_time (100, SC_NS));

  sc_close_vcd_trace_file (tf);
  return 0;
}

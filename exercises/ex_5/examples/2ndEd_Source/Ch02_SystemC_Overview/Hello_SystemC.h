#ifndef HELLO_SYSTEMC_H
#define HELLO_SYSTEMC_H
//FILE:Hello_SystemC.h
SC_MODULE(Hello_SystemC) {
  sc_core::sc_in_clk clk_pi;
  void main_method(void);
  SC_CTOR(Hello_SystemC) {
    SC_METHOD(main_method);
    sensitive << clk_pi.neg();
    dont_initialize();
  }
};
#endif

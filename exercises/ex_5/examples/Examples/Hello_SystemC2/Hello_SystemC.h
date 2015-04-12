//FILE:Hello_SystemC.h

#ifndef HELLO_SYSTEMC_H
#define HELLO_SYSTEMC_H

#include <systemc.h> 
#include <iostream>

//SC_MODULE(Hello_SystemC) {
class Hello_SystemC : public sc_module {

sc_in_clk clk_pi;

  void main_method(void);

  // SC_CTOR(Hello_SystemC) {
  Hello_SystemC (sc_module_name name) : sc_module (name) {
    SC_HAS_PROCESS(Hello_SystemC);
    
    SC_THREAD(main_method);
    sensitive << clk_pi.neg();
    dont_initialize();
  }
};

#endif

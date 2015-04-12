#ifndef BUFFER_EX_H
#define BUFFER_EX_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This example illustrates the simple difference between sc_signal
//   and sc_buffer.
//
// DESIGN HIERARCHY
//   sc_main()
//   +- buffer_ex_i
//    +- buffer_ex_thread
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>

SC_MODULE(buffer_ex) 
{
  sc_core::sc_signal<double> my_sig;
  sc_core::sc_buffer<double> my_buf;
  SC_CTOR(buffer_ex)
  {
    SC_THREAD(buffer_ex_thread);
    //sensitive << my_buf.pos(); // not supported by sc_buffer
    SC_METHOD(sig_method);
      sensitive << my_sig;
      dont_initialize();
    SC_METHOD(buf_method);
      sensitive << my_buf;
      dont_initialize();
  }
  
  void buffer_ex_thread(void);
  void sig_method(void);
  void buf_method(void);
};

#endif
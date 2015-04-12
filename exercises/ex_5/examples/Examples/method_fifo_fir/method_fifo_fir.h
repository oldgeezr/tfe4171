#ifndef SC_FIFO_EX_H
#define SC_FIFO_EX_H
//BEGIN method_fifo_fir.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This example illustrates how an SC_METHOD may be used with
//   sc_fifo's. Contrast this design to the fifo_fir design. Notice
//   how much simpler the thread approach is.
//
// Configuration file format:
//   +---------------------+
//   |N                    |
//   |COEFFICIENT_0        |
//   |COEFFICIENT_1        |
//   |COEFFICIENT_2        |
//   |...                  |
//   |COEFFICIENT_(N-1)    |
//   +---------------------+
//
// DESIGN HIERARCHY
//   sc_main()
//   +- sc_fifo_ex_i
//    +- stimulus_thread
//    +- fir_method
//    +- results_thread
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>

SC_MODULE(method_fifo_fir) {
  // communication between processes
  sc_fifo<double> orig_in;
  sc_fifo<double> data_in;
  sc_fifo<double> data_out;
  double*         m_pipe;     // data pipe array
  double*         m_coeff;    // array of coefficients
  unsigned        m_taps;     // number of coefficients
  unsigned        m_tap;      // current tap
  double          m_data;     // current data input
  double          m_result;   // current result
  enum method_states {READING,PROCESSING,WRITING};
  method_states m_state;

  SC_HAS_PROCESS(method_fifo_fir);
  // Constructor
  method_fifo_fir(sc_module_name _name, char* _cfg_filename="method_fifo_fir.cfg");
  // Destructor
  ~method_fifo_fir() {
    if (m_taps) {
      delete[] m_coeff;
      delete[] m_pipe;
    }//endif
  }//end ~method_fifo_fir()

  // Processes
  void stimulus_thread(void);
  void fir_method(void);
  void results_thread(void);
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: method_fifo_fir.h,v 1.3 2004/04/15 17:42:39 dcblack Exp $

//BEGIN method_fifo_fir.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See method_fifo_fir.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "method_fifo_fir.h"
#include <fstream>
#include <iomanip>
#include <cmath>

extern unsigned errors;
using std::cout;
using std::cerr;
using std::fixed;
using std::setw;
using std::setfill;
using std::setprecision;
using std::endl;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Constructor
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
method_fifo_fir::method_fifo_fir(sc_module_name _name, char* _cfg_filename) :
  sc_module(_name),
  m_taps(0),
  m_tap(0),
  m_state(READING),
  orig_in(5),
  data_in(5),
  data_out(5)
{
  SC_THREAD(stimulus_thread);
  SC_METHOD(fir_method);
  SC_THREAD(results_thread);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Read coefficients from configuration file and initialize pipe to zero
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  ifstream cfg_file(_cfg_filename);
  if (!cfg_file) {
    cerr << "ERROR: Problem opening " << _cfg_filename << " for input." << endl;
    errors++;
    return;
  }//endif
  cfg_file >> m_taps;
  if (m_taps < 1) {
    cerr << "ERROR: Number of taps must be greater than zero!" << endl;
    errors++;
    return;
  }//endif
  // Allocate memory
  m_pipe  = new double[m_taps];
  m_coeff = new double[m_taps];
  cout << "INFO(constructor): Initializing coefficients & pipe" << endl;
  for (unsigned tap=0;tap!=m_taps;tap++) {
    if (cfg_file.eof()) {
      cerr << "ERROR: Too few coefficients when reading [" << tap << "]." << endl;
      errors++;
      return;
    }//endif
    cfg_file >> m_coeff[tap];
    m_pipe[tap] = 0;
  }//endfor
}//end method_fifo_fir()

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Processes
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void method_fifo_fir::stimulus_thread(void) {
  unsigned PTS=20;
  for (unsigned t=0;t<PTS;t++) {
    double data = 0.0;
    if (t==10) data = 1.0; // impulse
    orig_in.write(data);
    data_in.write(data);
    cout << "INFO(stimulus_thread): Input " << data << endl;
  }//endfor
  wait(SC_ZERO_TIME);
  cout << "INFO(stimulus_thread): Done" << endl;
}//end stimulus_thread()

void method_fifo_fir::fir_method(void) {
  if (m_state == READING) {
    if (data_in.num_available() == 0) {
      cout << "INFO(fir_method): Waiting for data to read" << endl;
      next_trigger(data_in.data_written_event());
      return;
    } else {
      // read next piece of data
      cout << "INFO(fir_method): Reading data" << endl;
      if (data_in.nb_read(m_data)) { m_state = PROCESSING; }
    }//endif
  }//endif
  if (m_state == PROCESSING) {
    cout << "INFO(fir_method): Processing " << m_data << endl;
    unsigned coeff = m_tap; // used to index coeffiecients
    m_pipe[m_tap++] = m_data;
    if (m_tap == m_taps) m_tap = 0; // wrap
    m_result = 0;
    for (unsigned tap=0;tap!=m_taps;tap++,coeff++) {
      if (coeff == m_taps) coeff = 0; // wrap
      m_result += m_coeff[coeff] * m_pipe[tap];
    }//endfor
    m_state = WRITING;
  }//endif
  if (m_state == WRITING) {
    if (data_out.num_free() == 0) {
      cout << "INFO(fir_method): Waiting for results" << endl;
      next_trigger(data_out.data_read_event());
      return;
    } else {
      cout << "INFO(fir_method): Writing results" << endl;
      if (data_out.nb_write(m_result)) { 
        m_state = READING;
        next_trigger(SC_ZERO_TIME); // write to occur
      }
    }//endif
  }//endif
}//end fir_method()

void method_fifo_fir::results_thread(void) {
  for(unsigned i=0;;i++) {
    double data   =  orig_in.read();
    double result =  data_out.read();
    cout << "DATA: "
         << "["  << setw(2) << i << "]" 
         << "= " << setw(9) << fixed << setprecision(5) << data
         << " "  << setw(9) << fixed << setprecision(5) << result
         << endl;
  }//endforever
}//end results_thread()

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: method_fifo_fir.cpp,v 1.2 2004/02/02 12:38:46 dcblack Exp $

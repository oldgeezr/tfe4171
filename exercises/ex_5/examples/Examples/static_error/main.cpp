#include "static_error.h"

sc_event global_event;

int sc_main(int argc,char *argv[]) {
  cout << "INFO: Constructing/binding." << std::endl;

  const sc_time t_12NS(12,SC_NS);

  // Top-level channels
  sc_clock sigfnd("sigfnd",2);
  sc_clock sigevt("sigevt",3);
  sc_clock sigval("sigval",5);

  // Instantiate & connect disconnect
  static_error disconnect_i("disconnect_i");
  disconnect_i.sigfnd_pi(sigfnd);
  disconnect_i.sigevt_pi(sigevt);
  disconnect_i.sigval_pi(sigval);
  cout << "INFO: Elaboration complete." << std::endl;
  sc_start(t_12NS);
  return 0;
}//end sc_main()

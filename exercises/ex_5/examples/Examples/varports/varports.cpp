//BEGIN varports.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See varports.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "varports.h"

void varports::varports_thread(void) {
  for(;;) {
    wait(t_PROCESS);
    // Check all incoming ports for data
    for (unsigned i=0;i!=rcv_p.size();i++) {
      stats[rcv_p[i]->num_available()]++;
      m_processed++;
      int samples_read = 0;
      int rcvd;
      while (samples_read++ < m_samples_per_pass && rcv_p[i]->nb_read(rcvd)) {
        // Retransmit incoming data to all *other* ports
        for (unsigned j=0;j!=xmt_p.size();j++) {
          if (i!=j) {
            xmt_p[j]->write(rcvd);
          }//endif
        }//endfor j
        if (--m_samples_left == 0) goto DONE;
      }//endwhile
    }//endfor i
  }//endforever
  DONE:
  wait(SC_ZERO_TIME);
  cout << "INFO: Reached maximum sample count @ " << sc_time_stamp() << endl;
  sc_stop();
}//end varports::varports_thread

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: varports.cpp,v 1.1 2004/02/21 21:04:35 dcblack Exp $

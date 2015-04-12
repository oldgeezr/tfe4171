#ifndef BOARD_H
#define BOARD_H
//BEGIN Board.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  #include "switch.h"
  SC_MODULE(Board) {
    Switch switch_i;
    sc_fifo<int> t1A, t1B, t1C, t1D;
    sc_signal<bool> request[9];
    SC_CTOR(Board) : switch_i("switch_i") 
    {
      switch_i.T1_ip(t1A); switch_i.T1_ip(t1B);
      switch_i.T1_ip(t1C); switch_i.T1_ip(t1D);
      for (unsigned i=0;i!=9;i++) {
        switch_i.request_op(request[i]);
      }//endfor
      SC_THREAD(bored_thread);
    }//end constructor
    void bored_thread(void);
  };

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: Board.h,v 1.4 2004/04/15 17:45:10 dcblack Exp $

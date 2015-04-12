//BEGIN shift_register.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See shift_register.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "shift_register.h"

#include <iostream>
#include <iomanip>
using std::cout;
using std::setw;
using std::endl;

extern bool verbose;

const int END_COUNT=8;

void shift_register::flop1_thread(void) {
  for(int count=1;count<=END_COUNT;count++) {
    e_q1.notify(SC_ZERO_TIME);
    wait(t_SEC);
    if (verbose) {
      cout << "INFO:  " << setw(2) << sc_time_stamp() << "  ";
      cout << "                                          ";
      cout << "i1=" << m_q1 << "...";
    }//endif
    m_i1 = count;
    if (verbose) {
      cout << "i1=" << m_i1 << " ";
      cout << "q1=" << m_q1 << "...";
    }//endif
    m_q1 = count;
    if (verbose) {
      cout << "q1=" << m_q1 << " ";
      cout << endl;
    }//endif
  }//endfor
  wait(SC_ZERO_TIME);
  cout << "NOTE:  " << setw(2) << sc_time_stamp() << " "
       << " stopping"
       << endl;
  sc_stop();
  wait(SC_ZERO_TIME);
}//end flop1_thread()

void shift_register::flop2_thread(void) {
  for(;;) {
    e_q2.notify(SC_ZERO_TIME);
    wait(t_SEC);
    if (verbose) {
      cout << "INFO:  " << setw(2) << sc_time_stamp() << "  ";
      cout << "                                          ";
      cout << "i2=" << m_q2 << "...";
    }//endif
    m_i2 = m_i1;
    if (verbose) {
      cout << "i2=" << m_i2 << " ";
      cout << "q2=" << m_q2 << "...";
    }//endif
    m_q2 = m_q1;
    if (verbose) {
      cout << "q2=" << m_q2 << " ";
      cout << endl;
    }//endif
  }//endforever
}//end flop2_thread()

void shift_register::flop3_thread(void) {
  for(;;) {
    e_q3.notify(SC_ZERO_TIME);
    wait(t_SEC);
    if (verbose) {
      cout << "INFO:  " << setw(2) << sc_time_stamp() << "  ";
      cout << "                                          ";
      cout << "i3=" << m_q3 << "...";
    }//endif
    m_i3 = m_i2;
    if (verbose) {
      cout << "i3=" << m_i3 << " ";
      cout << "q3=" << m_q3 << "...";
    }//endif
    m_q3 = m_q2;
    if (verbose) {
      cout << "q3=" << m_q3 << " ";
      cout << endl;
    }//endif
  }//endforever
}//end flop3_thread()

void shift_register::flop4_thread(void) {
  for(;;) {
    e_q4.notify(SC_ZERO_TIME);
    wait(t_SEC);
    if (verbose) {
      cout << "INFO:  " << setw(2) << sc_time_stamp() << "  ";
      cout << "                                          ";
      cout << "i4=" << m_q4 << "...";
    }//endif
    m_i4 = m_i3;
    if (verbose) {
      cout << "i4=" << m_i4 << " ";
      cout << "q4=" << m_q4 << "...";
    }//endif
    m_q4 = m_q3;
    if (verbose) {
      cout << "q4=" << m_q4 << " ";
      cout << endl;
    }//endif
  }//endforever
}//end flop4_thread()

void shift_register::monitor_thread(void) {
  for(;;) {
    wait(e_q1 & e_q2 & e_q3 & e_q4);
    cout << "NOTE:  " << setw(2) << sc_time_stamp() << " "
         << " i1=" << m_i1
         << " i2=" << m_i2
         << " i3=" << m_i3
         << " i4=" << m_i4
         << " "
         << " q1=" << m_q1
         << " q2=" << m_q2
         << " q3=" << m_q3
         << " q4=" << m_q4
         << endl;
  }//endforever
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: shift_register.cpp,v 1.3 2004/02/02 12:46:14 dcblack Exp $

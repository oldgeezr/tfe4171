//BEGIN engine_time.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See engine_time.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "engine_time.h"

using std::cout;
using std::endl;

extern unsigned errors;

void engine_time::engine_time_thread(void) {
  const int MAXCYCLES = 6; // limit simulation cycles
  sc_time t_REV(1.0/(RPM*60),SC_SEC);
  cout << "INFO: One revolution takes " << t_REV << endl;
  sc_time t_OPEN_INTAKE   = 0.1 * t_REV;
  sc_time t_CLOSE_INTAKE  = 0.1 * t_REV;
  sc_time t_ADD_FUEL      = 0.1 * t_REV;
  sc_time t_COMPRESS      = 0.2 * t_REV;
  sc_time t_SPARK         = 0.1 * t_REV;
  sc_time t_EXPAND        = 0.2 * t_REV;
  sc_time t_OPEN_EXHAUST  = 0.1 * t_REV;
  sc_time t_CLOSE_EXHAUST = 0.1 * t_REV;
  for(int cycle=0;cycle!=MAXCYCLES;cycle++) {
    cout << "INFO: ***** STARTING CYCLE " << cycle << "*****" << endl;
    cout << "INFO: " << sc_time_stamp() << " Opening intake" << endl;
    wait(t_OPEN_INTAKE  );
    cout << "INFO: " << sc_time_stamp() << " Adding fuel mixture" << endl;
    wait(t_CLOSE_INTAKE );
    cout << "INFO: " << sc_time_stamp() << " Closing intake" << endl;
    wait(t_ADD_FUEL     );
    cout << "INFO: " << sc_time_stamp() << " Compressing gas" << endl;
    wait(t_COMPRESS     );
    cout << "INFO: " << sc_time_stamp() << " Applying spark" << endl;
    wait(t_SPARK        );
    cout << "INFO: " << sc_time_stamp() << " Expanding gas" << endl;
    wait(t_EXPAND       );
    cout << "INFO: " << sc_time_stamp() << " Opening exhaust valve" << endl;
    wait(t_OPEN_EXHAUST );
    cout << "INFO: " << sc_time_stamp() << " Closing exhaust valve" << endl;
    wait(t_CLOSE_EXHAUST);
  }//endforever
  cout << "ERROR: Exhausted simulation cycles" << endl;
  errors++;
}//end engine_time_thread()

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: engine_time.cpp,v 1.3 2004/02/02 12:33:23 dcblack Exp $

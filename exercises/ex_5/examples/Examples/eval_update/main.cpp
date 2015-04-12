//BEGIN eval_update/main.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See eval_update.h for a details.

#include "eval_update.h"

bool reorder;

int sc_main(int argc, char *argv[]) {
  if (argc > 1) {
    cout << "REORDERING" << endl;
    reorder = true;
  }//endif
  cout << "INFO: Elaborating" << endl;
  sc_clock clk("clk",3);
  Eval_Update shifter("shifter");
  shifter.clock(clk);
  cout << "INFO: simulating" << endl;
  sc_start();
  cout << "INFO: eval_update COMPLETED" << endl;
  return 0;
}//end sc_main()

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: main.cpp,v 1.2 2004/01/07 04:26:15 dcblack Exp $

#ifndef CYCLINDER_H
#define CYCLINDER_H
//BEGIN Cylinder.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See jalopy.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>

SC_MODULE(Cylinder) {
  // Constructor
  SC_CTOR(Cylinder) {
    cout << "INFO: Constructing instance " << name() << endl;
    SC_THREAD(Cylinder_thread);
  }//end Cylinder constructor
  // Processes
  void Cylinder_thread(void) {
    cout << "INFO: Ran Cylinder_thread inside instance " << name() << endl;
  }
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: Cylinder.h,v 1.1 2004/01/12 03:34:15 dcblack Exp $

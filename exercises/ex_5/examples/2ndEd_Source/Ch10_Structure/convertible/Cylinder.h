#ifndef CYCLINDER_H
#define CYCLINDER_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See sedan.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>

SC_MODULE(Cylinder) 
{
  // Constructor
  SC_HAS_PROCESS(Cylinder);
  Cylinder(sc_module_name nm);
  
  // Processes
  void Cylinder_thread(void);
};

#endif
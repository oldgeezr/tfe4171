#ifndef REPORT_H
#define REPORT_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This example illustrates the error reporting facilities of SystemC
//   version 2.1.
//
// DESIGN HIERARCHY
//   sc_main()
//   +- report_i
//      +- report_thread
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

SC_MODULE(report) 
{
  // Constructor
  report(sc_module_name nm);
  
  // Process declarations
  void report_thread();
};
#endif

// Portions COPYRIGHT (C) 2004-2009 ESLX Inc.------------------------ //
// Permission granted for anybody to use this template provided this  //
// acknowledgement of ESLX Inc. remains.                              //
//------------------------------------------------------------------- //
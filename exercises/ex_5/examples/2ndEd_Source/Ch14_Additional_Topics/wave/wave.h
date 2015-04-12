#ifndef WAVE_H
#define WAVE_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This design creates two signals and provides a
//   VCD (Value Change Dump) wave-form output file.
//
// DESIGN HIERARCHY
//   sc_main()
//   +- wave_i
//    +- wave_thread
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Module definition
SC_MODULE(wave) 
{
  // Local channel & submodule declarations
  sc_signal<bool>    oscillate;
  sc_signal<double>  pressure;
  sc_trace_file*  tracefile;
  
  // Constructor
  wave(sc_module_name nm); 
  ~wave();
  
  // Process declarations
  void wave_thread();
  
private:
  // Local data members
  double temperature;
  unsigned cylinder;
};
#endif
// Portions COPYRIGHT (C) 2004-2009 ESLX Inc. ----------------------- //
// Permission granted for anybody to use this template provided this  //
// acknowledgement of ESLX Inc. remains.                              //
//------------------------------------------------------------------- //

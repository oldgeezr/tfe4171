#ifndef INTERFACES_H
#define INTERFACES_H

  // Interface typedefs to match diagram
  typedef sc_signal_in_if<int>    if1;
  typedef sc_signal_in_if<int>    if2;
  typedef sc_signal_out_if<int>   if3;
  typedef sc_signal_inout_if<int> if4;
  typedef sc_signal_out_if<int>   if5;
  typedef sc_signal_out_if<int>   if6;
  typedef sc_signal_in_if<int>    ifB;
  typedef sc_signal_in_if<int>    ifD;
  typedef sc_signal_in_if<int>    ifF;
  typedef sc_signal_in_if<int>    ifW;
  typedef sc_signal_in_if<int>    ifX;
  typedef sc_signal_in_if<int>    ifY;
  typedef sc_signal_in_if<int>    ifZ;
  typedef sc_signal<int>          ch1;
  typedef sc_signal<int>          ch2;
  typedef sc_signal<int>          ch3;
  typedef sc_signal<int>          chC;
  typedef sc_signal<int>          chG;
#endif

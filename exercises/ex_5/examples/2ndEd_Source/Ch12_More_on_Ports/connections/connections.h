#ifndef CONNECTIONS_H
#define CONNECTIONS_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This module implements the connections shown in diagrams of
//   chapters 9 & 10.
//
// DESIGN HIERARCHY
//   sc_main()
//   +- top
//    +- m1 mi1
//    +- m2 mi2
//    +- SC_THREAD pr1
//    +- SC_THREAD pr2
//    +- SC_THREAD pr3
//   +- m3 mi3
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>
#include <interfaces.h>
#include "m1.h"
#include "m2.h"

SC_MODULE(connections) 
{
  // Ports
  sc_port<if1>   p1;
  sc_port<if2>   p2;
  sc_port<if3>   p3;
  sc_port<if4>   p4;
  sc_export<if5> p5;
  sc_export<if6> p6;
  
  // Channels
  ch1* c1i;
  ch2* c2i;
  ch3* c3i;
  
  // Instances
  m1* mi1;
  m2* mi2;
  
  // Events
  sc_event ev1;
  sc_event ev2;
  
  // Constructor
  SC_HAS_PROCESS(connections);
  connections(sc_module_name nm);
  
  // Processes
  void pr1(void);
  void pr2(void);
  void pr3(void);
};

#endif
//BEGIN connections.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See connections.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "connections.h"

connections::connections(sc_module_name nm)
: p1("p1"), // label ports to aid debug
  p2("p2"),
  p3("p3"),
  p4("p4"),
#ifdef SYSTEMC_V2_1
  p5("p5"),
  p6("p6"),
#endif
  sc_module(nm)
{
#ifdef SYSTEMC_V2_1
  cout << "INFO: Using SystemC 2.1 features" << endl;
#endif
  // Register processes
  SC_THREAD(pr1);
  SC_THREAD(pr2);
  SC_THREAD(pr3);
  // Channel instances
  c1i = new ch1("c1i"); // label channels to aid debug
  c2i = new ch2("c2i");
  c3i = new ch3("c3i");
  // Module instances
  mi1 = new m1("mi1");
  mi2 = new m2("mi2");
  // Internal connections
  mi1->pA(p1);
  mi1->pB(*c1i);
  mi2->pD(*c1i);
  mi2->pD(mi1->pC);
  mi2->pE(p3);
  mi2->pF(*c3i);
#ifdef SYSTEMC_V2_1
  p5(*c3i);
  p6(mi1->pG);
#endif
  // Connections to processes are implicit by way of
  // their usage within the processes themselves.
}
void connections::pr1(void) {
}//end pr1()

void connections::pr2(void) {
}//end pr2()

void connections::pr3(void) {
}//end pr3()

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: connections.cpp,v 1.7 2004/02/02 12:31:26 dcblack Exp $

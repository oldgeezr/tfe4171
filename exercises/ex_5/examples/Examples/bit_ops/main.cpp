//FILE: main.cpp (systemc)
//# vim600:set sw=2 tw=0 fdm=marker:
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//DESCRIPTION
//  This example illustrates the sc_bit and sc_bv data types and
//  common operations.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
using std::cout;
using std::endl;

#include <systemc.h>

char* simulation_name = "bit_ops";
char* simulation_vers = "$Header: /eklectICally/Project/ea/Cvsroot/Book2003/Examples/bit_ops/main.cpp,v 1.1 2004/03/02 22:08:18 dcblack Exp $";

int sc_main(int argc, char* argv[]) {
  sc_bit flag(SC_LOGIC_1); // more efficient to use bool
  sc_bv<5> positions = "01101";
  sc_bv<6> mask = "100111";
  sc_bv<5> active = positions & mask;// 00101
  sc_bv<1> all = active.and_reduce(); // SC_LOGIC_0
  positions.range(3,2) = "00";// 00001
  positions[2] = active[0] ^ flag;
  cout << "INFO: positions is '" << positions << "'" << endl;
  cout << "INFO:      mask is '" << mask      << "'" << endl;
  cout << "INFO:    active is '" << active    << "'" << endl;
  cout << "INFO:      flag is '" << flag      << "'" << endl;
  cout << "INFO:       all is '" << all       << "'" << endl;
}

//Portions COPYRIGHT (C) 2003-2004 Eklectic Ally, Inc.-------------{{{//
// Permission granted for anybody to use this example provided this   //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//-----------------------------------------------------------------}}}//
//END $Id: main.cpp,v 1.1 2004/03/02 22:08:18 dcblack Exp $

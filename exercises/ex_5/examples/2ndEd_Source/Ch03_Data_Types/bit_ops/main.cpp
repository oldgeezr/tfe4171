//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//DESCRIPTION
//  This example illustrates the sc_bit and sc_bv data types and
//  common operations.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
using std::cout;
using std::endl;

#include <systemc>
using namespace sc_dt; 
const char* simulation_name = "bit_ops";

int sc_main(int argc, char* argv[]) 
{
  sc_core::sc_report_handler::set_actions("/IEEE_Std_1666/deprecated", sc_core::SC_DO_NOTHING);
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
  return 0;
}

// Portions COPYRIGHT (C) 2003-2009 ESLX, Inc.---------------------//
// Permission granted for anybody to use this example provided this//
// acknowledgement of ESLX, Inc. remains.                          //
//-----------------------------------------------------------------//

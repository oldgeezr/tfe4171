//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   Simple example of sc_logic and sc_lv. These are defined in
//   $SYSTEMC/include/systemc/bit/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
using std::cout;
using std::endl;

#include <systemc>
using namespace sc_dt; 
const char* simulation_name = "logic";

int sc_main(int argc, char* argv[]) 
{
  sc_logic buf(sc_dt::Log_Z);
  sc_lv<8> data_drive("zz01XZ1Z");
  data_drive.range(5,4) = "ZZ";// ZZZZXZ1Z
  buf = '1';
  buf = SC_LOGIC_1;
  cout << "INFO: buf is '" << buf << "'" << endl;
  cout << "INFO: data_drive is '" << data_drive << "'" << endl;
  return 0;
}

// Portions COPYRIGHT (C) 2003-2009 ESLX Inc.------------------------ //
// Permission granted for anybody to use this example provided this   //
// acknowledgement of ESLX Inc. remains                               //
//------------------------------------------------------------------- //

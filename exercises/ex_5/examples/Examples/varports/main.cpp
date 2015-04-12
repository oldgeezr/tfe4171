//FILE: main.cpp (systemc)
//# vim600: set sw=2 tw=0 fdm=marker:
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See varports.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
using std::cout;
using std::endl;

#include <systemc.h>
#include "varports.h"
#include "device.h"

unsigned errors = 0;
char* simulation_name = "varports";
char* simulation_vers = "$Header: /eklectICally/Project/ea/Cvsroot/Book2003/Examples/varports/main.cpp,v 1.1 2004/02/21 21:04:35 dcblack Exp $";

int sc_main(int argc, char* argv[]) {
  // Time must be setup before sc_time used
  sc_set_time_resolution(1,SC_PS);
  sc_set_default_time_unit(1,SC_NS);
  // Configuration defaults
  const unsigned MAX_DEVICES = 16;
  unsigned nDevices = 6;
  unsigned fifo_depth = 6;
  unsigned number_of_samples = 20000;
  unsigned process_max = 2;
  sc_time  t_SAMPLE(40,SC_NS);
  cout << simulation_name << " " << simulation_vers << endl;
  cout << "--------------------------------------------------" << endl;
  //----------------------------------------------------------------------------
  // Note configuration
  cout << "INFO: FIFO's set to " << fifo_depth << " entries" << endl;
  cout << "INFO: Connecting " << nDevices << " ports" << endl;
  cout << "INFO: Taking " << number_of_samples << " samples" << endl;
  cout << "INFO: Processing up to " << process_max << " samples per pass" << endl;
  cout << "INFO: Sampling every " << t_SAMPLE << endl;
  //----------------------------------------------------------------------------
  // Begin SystemC setup
  //----------------------------------------------------------------------------
  cout << "INFO: Elaborating "<< simulation_name << endl; //{{{
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Programmable structure
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  varports*     varports_i;
  // allow for up to MAX_DEVICES devices
  device*       device_i[MAX_DEVICES];
  sc_fifo<int>* v2d[MAX_DEVICES];
  sc_fifo<int>* d2v[MAX_DEVICES];
  varports_i = new varports("varports_i",t_SAMPLE,2,fifo_depth,number_of_samples);
  for (unsigned i=0;i!=nDevices;i++) {
    sc_string nm; // use for unique device/channel instance names
    // Create device
    nm =  sc_string::to_string("device_name_i[%d]",i);
    device_i[i] = new device(nm.c_str());
    // Create channels to use when connecting device
    nm =  sc_string::to_string("v2d[%d]",i);
    v2d[i] = new sc_fifo<int>(nm.c_str(),fifo_depth);
    nm =  sc_string::to_string("d2v[%d]",i);
    d2v[i] = new sc_fifo<int>(nm.c_str(),fifo_depth);
    // Connect device to device channels
    device_i[i]->rcv_p(*v2d[i]);
    device_i[i]->xmt_p(*d2v[i]);
    // Connect device channel to varports
    varports_i->rcv_p(*d2v[i]);
    varports_i->xmt_p(*v2d[i]);
  }//endfor
  //-------------------------------------------------------------------------}}}
  cout << "-------- END ELABORATION -------------------------" << endl;
  cout << "INFO: Simulating "<< simulation_name << endl;
  sc_start();
  cout << "-------- END SIMULATION --------------------------" << endl;
  cout << "INFO: Post-processing "<< simulation_name  // {{{
       << " at " << sc_time_stamp()
       << endl;
  int samples = 0;
  for (unsigned i=0;i<=fifo_depth;i++) {
    samples += i*varports_i->stats[i];
    cout << "INFO: varports_i->stats[" << i << "]"
         << "=" << varports_i->stats[i]
         << endl;
  }//endfor
  cout << "INFO: Total " << samples << " samples" << endl;
  // Cleanup
  for (unsigned i=0;i!=nDevices;i++) {
    delete device_i[i];
    delete v2d[i];
    delete d2v[i];
  }//endfor
  cout << "-------- END POST-PROCESS ------------------------" << endl;
  cout << "INFO: Simulation " << simulation_name
       << " " << (errors?"FAILED":"PASSED")
       << " with " << errors << " errors"
       << endl;
  return errors?1:0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: main.cpp,v 1.1 2004/02/21 21:04:35 dcblack Exp $

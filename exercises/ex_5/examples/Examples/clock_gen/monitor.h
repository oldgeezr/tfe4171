#ifndef MONITOR_H
#define MONITOR_H
//BEGIN monitor.h (systemc)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// See clock_gen.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

SC_MODULE(monitor) {
  sc_in<bool> clk1_p;
  sc_in<bool> clk2_p;
  SC_CTOR(monitor) {
    SC_METHOD(clk1_method);
    sensitive << clk1_p;
    SC_METHOD(clk2_method);
    sensitive << clk2_p;
  }
  void clk1_method() {
    cout << "INFO: "<< name() 
         << " clk1=" << clk1_p->read()
         << " at " << sc_time_stamp() << endl;
  }
  void clk2_method() {
    cout << "INFO: "<< name() 
         << " clk2=" << clk2_p->read()
         << " at " << sc_time_stamp() << endl;
  }
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: monitor.h,v 1.2 2004/04/15 17:37:29 dcblack Exp $

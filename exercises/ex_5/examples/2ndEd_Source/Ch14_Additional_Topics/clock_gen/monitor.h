#ifndef MONITOR_H
#define MONITOR_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// See clock_gen.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

SC_MODULE(monitor) 
{
  sc_in<bool> clk1_p;
  sc_in<bool> clk2_p;
  
  // Constructor
  SC_CTOR(monitor) 
  {
    SC_METHOD(clk1_method);
      sensitive << clk1_p;
    SC_METHOD(clk2_method);
      sensitive << clk2_p;
  }
  
  // method desclartions and implementations
  void clk1_method() 
  {
    cout << "INFO: "<< name() 
         << " clk1=" << clk1_p->read()
         << " at " << sc_time_stamp() << endl;
  } // end clk1_method
  
  void clk2_method() 
  {
    cout << "INFO: "<< name() 
         << " clk2=" << clk2_p->read()
         << " at " << sc_time_stamp() << endl;
  } // end clk2_method
};

#endif
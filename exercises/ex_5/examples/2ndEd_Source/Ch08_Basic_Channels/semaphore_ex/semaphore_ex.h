#ifndef SEMAPHORE_EX_H
#define SEMAPHORE_EX_H
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   TO_BE_SUPPLIED
//
// DESIGN HIERARCHY
//   sc_main()
//   +- semaphore_ex_i
//    +- customer1_thread
//    +- customer2_thread
//    +- customer3_thread
//    +- customer4_thread
//    +- customer5_thread
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>

SC_MODULE(semaphore_ex) 
{
  sc_core::sc_time MINS;
  unsigned fills;
  sc_core::sc_semaphore pump;
  sc_core::sc_event e_change;
  
  SC_CTOR(semaphore_ex) 
  : pump(2)
  , MINS(1,sc_core::SC_SEC)
  , fills(35)
  {
    SC_THREAD(customer1_thread);
    SC_THREAD(customer2_thread);
    SC_THREAD(customer3_thread);
    SC_THREAD(customer4_thread);
    SC_THREAD(customer5_thread);
    SC_METHOD(monitor_method);
      sensitive << e_change;
  }

  // Process methods
  void customer1_thread(void);
  void customer2_thread(void);
  void customer3_thread(void);
  void customer4_thread(void);
  void customer5_thread(void);
  void monitor_method(void);

  // Helper methods
  void customer(const char* who);
  void delay(sc_core::sc_time t, int uncertainty);
  void note(const char* who, const char* message);
};

#endif
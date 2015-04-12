#ifndef EVAL_UPDATE_H
#define EVAL_UPDATE_H
//BEGIN eval_update/eval_update.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This SystemC example illustrates the use of evaluate update.
//
// SYNTAX
//   eval_update.x [reorder]
//
// OPTIONS
//
//   Specifying 'reorder' (actually any argument) will change
//   the elaboration order of the Q1/Q2 methods. Results should
//   not change.
//
// DESIGN HIERARCHY
//   sc_main()
//    +- sc_clock clock
//    +- Eval_Update shifter(clock)
//       +- sc_signal Q1, Q2
//       +- Q1_method() << clock.pos
//       +- Q2_method() << clock.pos
//       +- testbench_thread()
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


#include <systemc.h>

extern bool reorder;

SC_MODULE(Eval_Update) {
  sc_in<bool> clock;
  int D;
  sc_signal<int> Q1, Q2;
  SC_CTOR(Eval_Update) {
    SC_THREAD(testbench_thread);
    if (reorder) {
      SC_METHOD(Q2_method); sensitive << clock.pos(); dont_initialize();
      SC_METHOD(Q1_method); sensitive << clock.pos(); dont_initialize();
    } else {
      SC_METHOD(Q1_method); sensitive << clock.pos(); dont_initialize();
      SC_METHOD(Q2_method); sensitive << clock.pos(); dont_initialize();
    }//endif
  }//end SC_CTOR
  void Q1_method(void);
  void Q2_method(void);
  void testbench_thread(void);

};//end SC_MODULE(Eval_Update)

#endif

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: eval_update.h,v 1.4 2004/04/15 17:38:43 dcblack Exp $

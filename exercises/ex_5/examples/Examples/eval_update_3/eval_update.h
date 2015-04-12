// -*- c++ -*-
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

class my_smart_signal
: public sc_module
{
public:
    my_smart_signal (sc_module_name n) : sc_module (n) 
    {
	val = newv = 0;
	SC_HAS_PROCESS(my_smart_signal);
	SC_METHOD(updateval);
	sensitive << upd;
    }

    int read () 
    {
	cout << "@" 
	     << sc_time_stamp() 
	     << "(" 
	     << sc_delta_count() 
	     << "): "
	     << name() 
	     << ".read(" 
	     << val 
	     << ")" 
	     << std::endl;
	return val; 
    }

    void write (int v) 
    {
	cout << "@" 
	     << sc_time_stamp() 
	     << "(" 
	     << sc_delta_count() 
	     << "): "
	     << name() 
	     << ".write(" 
	     << v 
	     << ")" 
	     << std::endl;
	newv = v;
	upd.notify (SC_ZERO_TIME);
    }

    void updateval () 
    {	
	cout << "@" 
	     << sc_time_stamp() 
	     << "(" 
	     << sc_delta_count() 
	     << "): "
	     << name() 
	     << ".updateval(" 
	     << val
	     << "->"
	     << newv
	     << ")" 
	     << std::endl;
	val = newv; 
    }
private:
    int val;
    int newv;
    sc_event upd;
};

SC_MODULE(Eval_Update) {
  sc_in<bool> clock;
  int D;
  my_smart_signal Q1, Q2;
  SC_CTOR(Eval_Update)
      : Q1 ("Q1"), Q2 ("Q2")
  {
    if (reorder) {
      SC_METHOD(Q2_method); sensitive << clock.pos(); dont_initialize();
      SC_METHOD(Q1_method); sensitive << clock.pos(); dont_initialize();
    } else {
      SC_METHOD(Q1_method); sensitive << clock.pos(); dont_initialize();
      SC_METHOD(Q2_method); sensitive << clock.pos(); dont_initialize();
    }//endif
    SC_THREAD(testbench_thread);
  }//end SC_CTOR
  void Q1_method(void);
  void Q2_method(void);
  void testbench_thread(void);

};//end SC_MODULE(Eval_Update)

#endif

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: eval_update.h,v 1.4 2004/04/15 17:38:43 dcblack Exp $

//BEGIN static_sensitivity.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   Static sensitivity lists are a frequent source of confusion in
//   SystemC because the error messages refer to a port not being
//   bound which directs the reader to the location of the binding
//   rather than the real cause of the error. By contrast, dynamic
//   sensitivity lists involving wait() and next_trigger() tend to be
//   coded correctly, because the error messages point directly to the
//   statements involved.
//
//    This code example attempts to clarify static sensitivity
//   list usage. The example consists of two modules, testbench
//   and nerves_example. The testbench is merely a stimulus. The
//   nerves_example is where all the action is. Pay close attention to
//   the various static sensitivities illustrated after the 'sensitive'
//   statement.
//
// EXPLANATION
//   Static sensitivity is defined in the constructor of a module and is
//   thus executed *before* ports have been bound. This means that the
//   sensitive method has to somehow acquire information about an event
//   in a channel instance that it has no knowledge of at the time of
//   invocation. This is accomplished by creating a construct known as
//   an sc_event_finder that defers binding the event until the end of
//   elaboration.
//
//   By default ports have an sc_event_finder for a
//   default_event(). Thus it is legal to be sensitive to a simple
//   sc_port<sc_signal_*_if<>>. If and only if static sensitivity needs
//   to be setup on something other than the default_event(), then a
//   specialized port needs to be created.
//
//   For sc_signal_*_if, and sc_fifo_*_if, these specialized
//   ports already exist. A custom interface requires deriving a
//   custom specialized port. This is illustrated herein with the
//   ea_port_sc_signal_in_if_bool.
//
// SIDE NOTE
//   The name of the example module attempts a humorous play of words
//   considering how _sensitive_ nerves are. Especially when struggling
//   with the SystemC error messages. The typical error message when
//   the sensitive arguments are incorrect is:
//
//     Error: (E112) get interface failed: port is  
//     not bound: port 'nerves_i.port_1' (sc_port)
//   
//   This is precisely because the sensitive statement occurs prior
//   to port binding.
//
//   NOTE: To see the above, try:
//
//     CFLAGS=-DERROR make clean static_sensitivity
//
// SYNTAX
//   static_sensitivity.x
//
// DESIGN HIERARCHY
//   sc_main()
//    +- sc_clock clk
//    +- sc_signal<bool> signal
//    +- sc_signal<bool> sigpos
//    +- sc_fifo<bool>   fifo
//    +- sc_signal<bool> special
//    +- sc_signal<bool> specneg
//    +- testbench       testbench_i
//    |  +- SC_THREAD    test_thread()
//    +- nerves_example  nerves_i
//       +- SC_METHOD    nervous_method()
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc.h>

sc_event global_event;

SC_MODULE(testbench) {
  sc_port<sc_signal_out_if<bool> > signal_po;
  sc_port<sc_signal_out_if<bool> > sigpos_po;
  sc_port<sc_fifo_out_if<bool> >   fifo_po;
  sc_out<bool>                     special_po;
  sc_out<bool>                     specneg_po;

  SC_CTOR(testbench) {
    SC_THREAD(test_thread);
  }//end SC_CTOR

  void test_thread(void) {
    // Fire an ordinary event
    wait(1,SC_SEC);
    cout << "INFO: test_thread firing global_event at " << sc_time_stamp() << endl;
    global_event.notify(SC_ZERO_TIME);

    // Fire a signal
    for (unsigned i=0;i!=2;i++) {
      wait(1,SC_SEC);
      cout << "INFO: test_thread writing to signal_po at " << sc_time_stamp() << endl;
      signal_po->write(i==1);
    }//endfor

    // Fire a signal
    for (unsigned i=0;i!=2;i++) {
      wait(1,SC_SEC);
      cout << "INFO: test_thread writing to sigpos_po at " << sc_time_stamp() << endl;
      sigpos_po->write(i==1);
    }//endfor

    // Fire a fifo
    wait(1,SC_SEC);
    cout << "INFO: test_thread writing true to fifo_po at " << sc_time_stamp() << endl;
    fifo_po->write(true);

    // Fire a signal
    for (unsigned i=0;i!=2;i++) {
      wait(1,SC_SEC);
      cout << "INFO: test_thread writing to special_po at " << sc_time_stamp() << endl;
      special_po->write(i==1);
    }//endfor

    // Fire a signal
    for (unsigned i=0;i!=2;i++) {
      wait(1,SC_SEC);
      cout << "INFO: test_thread writing to specneg_po at " << sc_time_stamp() << endl;
      specneg_po->write(i==1);
    }//endfor

    // Allow clock to fire
    wait(10,SC_SEC);
    cout << "INFO: test_thread exiting at " << sc_time_stamp() << endl;
    sc_stop();
  }//end test_thread()

};//end SC_MODULE(testbench)

// Following is an example of creating a specialized port to
// support an event finder
class ea_port_sc_signal_in_if_bool: public sc_port<sc_signal_in_if<bool>,1> {
  typedef sc_signal_in_if<bool> if_type; // simplify typing
  public:
  sc_event_finder& ef_posedge_event() const {
      return *new sc_event_finder_t<if_type>(
          *this, &if_type::posedge_event );
  }//end ef_posedge_event()
};

SC_MODULE(nerves_example) {
  sc_in_clk                       special_clk;
  sc_port<sc_signal_in_if<bool> > signal_pi;
  ea_port_sc_signal_in_if_bool    sigpos_pi;
  sc_fifo_in<bool>                fifo_pi;
  sc_in<bool>                     special_pi;
  sc_in<bool>                     specneg_pi;

  SC_CTOR(nerves_example) {
    SC_METHOD(nervous_method);
    sensitive
      << global_event                 // simple defined event
      << signal_pi                    // use default event_finder
      << sigpos_pi.ef_posedge_event() // use custom event_finder
      << fifo_pi.data_written()       // use predefined event_finder
      << special_pi                   // use default event_finder
      << specneg_pi.neg()             // use predefined event_finder
      << special_clk.pos()            // use predefined event_finder
#ifdef ERROR
      << signal_pi->posedge_event()   // ERROR(runtime): not an event finder
#endif
      ;
  }//end SC_CTOR

  void nervous_method(void) {
    bool v;
    cout << "INFO: nervous_method fired at " << sc_time_stamp() << endl;
    if (signal_pi->event()  ) cout << "INFO: - signal_pi="   << signal_pi->read()   << endl;
    if (sigpos_pi->event()  ) cout << "INFO: - sigpos_pi="   << sigpos_pi->read()   << endl;
    if (fifo_pi->nb_read(v) ) cout << "INFO: - fifo_pi="     << v                   << endl;
    if (special_pi->event() ) cout << "INFO: - special_pi="  << special_pi->read()  << endl;
    if (specneg_pi->event() ) cout << "INFO: - specneg_pi="  << specneg_pi->read()  << endl;
    if (special_clk->event()) cout << "INFO: - special_clk=" << special_clk->read() << endl;
  }//end nervous_method()

};//end SC_MODULE(nerves_example)

int sc_main(int argc,char *argv[]) {
  cout << "INFO: Elaborating (constructing/binding)" << std::endl;

  // Top-level channels
  const sc_time t_PERIOD(7.5,SC_SEC);
  sc_clock clk("clk",t_PERIOD);
  sc_signal<bool> signal("signal");
  sc_signal<bool> sigpos;
  sc_fifo<bool>   fifo;
  sc_signal<bool> special;
  sc_signal<bool> specneg;

  // Instantiate & connect testbench
  testbench testbench_i("testbench_i");
  testbench_i.signal_po(signal);
  testbench_i.sigpos_po(sigpos);
  testbench_i.fifo_po(fifo);
  testbench_i.special_po(special);
  testbench_i.specneg_po(specneg);

  // Instantiate & connect nerves_example
  nerves_example nerves_i("nerves_i");
  nerves_i.signal_pi(signal);
  nerves_i.sigpos_pi(sigpos);
  nerves_i.fifo_pi(fifo);
  nerves_i.special_pi(special);
  nerves_i.specneg_pi(specneg);
  nerves_i.special_clk(clk);

  cout << "INFO: Starting simulation." << std::endl;
  sc_start();
  cout << "INFO: Stopped simulating at " << sc_time_stamp() << "." << std::endl;
  cout << "INFO: static_sensitivity COMPLETED" << endl;
  return 0;
}//end sc_main()

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: static_sensitivity.cpp,v 1.2 2004/02/02 12:46:14 dcblack Exp $

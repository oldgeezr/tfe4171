#ifndef arbitrator_H
#define arbitrator_H
//FILE: arbitrator.h (systemc)
//# vim600:set sw=2 tw=0 fdm=marker:
// Submodule class declarations
// Module definition
SC_MODULE(arbitrator) {
  // Ports
  sc_in<bool>  request_ip;
  sc_out<bool> grant_op;  
  sc_in_clk    clock_ip;  
  arbitrator(sc_module_name nm,sc_clock& clock);//Constructor
  // Processe declarations
  void arbitrator_thread();
  // Private data
private:
  sc_clock& m_clock;
};
#endif
//Portions COPYRIGHT (C) 2004 Eklectic Ally, Inc.------------------{{{//
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//-----------------------------------------------------------------}}}//
//END $Id: arbitrator.h,v 1.2 2004/04/15 17:45:26 dcblack Exp $

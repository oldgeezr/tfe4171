// YCRCB_Mixer.h
SC_MODULE(YCRCB_Mixer) 
{
	sc_port<sc_fifo_out_if<MIXER_state> > y_status;
	sc_port<sc_fifo_in_if<float> >        K_pi;
	sc_port<sc_fifo_in_if<YCRCB_frame> >  a_pi;
	sc_port<sc_fifo_in_if<YCRCB_frame> >  b_pi;
  sc_port<sc_fifo_out_if<YCRCB_frame> > y_po;
  
	void do_mix();
  
	SC_CTOR(YCRCB_Mixer){
		SC_THREAD(do_mix);
	} 
};


// Rgb2YCrCb.h
SC_MODULE(Rgb2YCrCb) 
{
	sc_port<sc_fifo_in_if<RGB_frame> >  rgb_pi;
	sc_port<sc_fifo_out_if<YCRCB_frame> > ycrcb_po;
  
	void do_convert();
  
	SC_CTOR(Rgb2YCrCb)
  {
    SC_THREAD(do_convert);
	}
};


// And-eksempel

#include <systemc.h>

typedef sc_in < bool > inflag;
typedef sc_out < bool > outflag;
typedef sc_signal < bool > flag;

SC_MODULE(andm) {
  sc_in<bool> a, b;
  sc_out<bool> c;

  SC_CTOR(andm) {
    SC_METHOD(xyz);
    sensitive << a << b;
  }
  
  void xyz () {
    bool x = a.read (), y = b.read ();
    c.write(x && y);
  }
};

SC_MODULE(tb) {
  SC_CTOR(tb) {
    SC_THREAD (bitr);

    andm andm1 ("andm");
    andm1.a (ai);
    andm1.b (bi);
    andm1.c (ci);

  }

  sc_signal<bool> ai, bi, ci;

  void bitr () {
    int c = 0;

    ai = false;
    bi = false;

    cout << "running" << endl;
    while (true) {
      wait (sc_time (5, SC_NS));
      c += 1;
      ai = (c % 2 > 0);
      bi = (c % 4 > 2);
    }
  }

};

int sc_main (int argc, char * argv[]) {
  const sc_time t_sim (100, SC_NS);
  
   sc_trace_file * otf = sc_create_vcd_trace_file ("output");
  
  tb tb1 ("tb");

   sc_trace (otf, tb1.ai, "in1");
   sc_trace (otf, tb1.bi, "in2");
   sc_trace (otf, tb1.ci, "o");
  
  
  sc_start (t_sim);

   sc_close_vcd_trace_file (otf);
}

#include <systemc.h>
#include "ea_pcix_trans.h"
#include <iomanip>
using std::setw;
using std::setfill;
using std::uppercase;

// Print a PCIX transaction packet out to a stream (usually just the terminal
// window), in a nice-looking format
ostream& operator<<(ostream& os, const ea_pcix_trans& trans) 
{
  os << "{" << endl
     << "  cmnd: " << "0x" << hex << setw(8) << trans.cmnd    << ", "
     << "attr1:"   << "0x" << hex << setw(8) << trans.attr1   << ", "
     << "attr2:"   << "0x" << hex << setw(8) << trans.attr2   << "," 
     << endl
     << "  devnum:"<< "0x" << trans.devnum  << ", "
     << "addr:"    << "0x" << trans.addr    << "," 
     << endl
     << "  data: " << "0x" << hex << setw(8) << setfill('0') << uppercase << trans.data[0] 
                   << ":"  << hex << setw(8) << trans.data[1] 
                   << ":"  << hex << setw(8) << trans.data[2] 
                   << ":"  << hex << setw(8) << trans.data[3] 
                   << ":"  << hex << setw(8) << trans.data[4] 
                   << ":"  << hex << setw(8) << trans.data[5] 
                   << ":"  << hex << setw(8) << trans.data[6] 
                   << ":"  << hex << setw(8) << trans.data[7] 
                   << "," 
     << endl
     << "  done:"  << (trans.done?"true":"false")  
     << endl
     << "}";                       
  return os;
}//end operator<<

// trace function, only required if actually used
void sc_trace(sc_trace_file* tf, const ea_pcix_trans& trans, const string& nm) 
{
  sc_trace(tf, trans.devnum,   nm + ".devnum" );
  sc_trace(tf, trans.addr,     nm + ".addr"   );
  sc_trace(tf, trans.attr1,    nm + ".attr1"  );
  sc_trace(tf, trans.attr2,    nm + ".attr2"  );
  sc_trace(tf, trans.cmnd,     nm + ".cmnd"   );
  sc_trace(tf, trans.data[0],  nm + ".data[0]");
  sc_trace(tf, trans.data[1],  nm + ".data[1]");
  sc_trace(tf, trans.data[2],  nm + ".data[2]");
  sc_trace(tf, trans.data[3],  nm + ".data[3]");
  sc_trace(tf, trans.data[4],  nm + ".data[4]");
  sc_trace(tf, trans.data[5],  nm + ".data[5]");
  sc_trace(tf, trans.data[6],  nm + ".data[6]");
  sc_trace(tf, trans.data[7],  nm + ".data[7]");
  sc_trace(tf, trans.done,     nm + ".done"   );
}//end sc_trace

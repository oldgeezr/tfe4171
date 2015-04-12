#ifndef EA_PULLUP_H
#define EA_PULLUP_H
//BEGIN ea_pullup.h (systemc)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This class, ea_pullup, behaves like an sc_signal_resolved with an
//   implicit weak pull-up resistor. If all sources write sc_logic_Z to
//   it, then the default sc_logic_1 will result. Otherwise works like a
//   sc_signal_resolved.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


#include <systemc.h>

class ea_pullup: public sc_signal_resolved {
public:
  // constructors
  ea_pullup() {} 
  explicit ea_pullup(const char* name_ ) :sc_signal_resolved(name_) {}
  // the fix
  virtual void update();
};

inline void ea_pullup::update() {
  sc_logic_resolve::resolve( m_new_val, m_val_vec );
  if (m_new_val == SC_LOGIC_Z) {
    m_new_val = SC_LOGIC_1;
  }//endif
  base_type::update();
}

template <int W>
class ea_pullup_pack: public sc_signal_rv<W> {
public:
  // constructors
  ea_pullup_pack() {} 
  explicit ea_pullup_pack(const char* name_ ) :sc_signal_rv<W>(name_) {}
protected:
  // the fix
  virtual void update();
};

template <int W>
inline void ea_pullup_pack<W>::update() {
  sc_lv_resolve<lv>::resolve( this->m_new_val, m_val_vec );
  for (unsigned i=0;i!=W;i++) {
    if (m_new_val[i] == SC_LOGIC_Z) {
      m_new_val[i]=SC_LOGIC_1;
    }//endif
  }//endfor
  base_type::update();
}
#endif

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END ea_pullup.h

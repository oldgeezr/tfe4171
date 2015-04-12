//BEGIN Genghis.inc (systemc)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
extern int errors;

Genghis::Genghis() // Constructor
: m_valid(false),
  m_id('a')
{
}//end Genghis::Genghis


void Genghis::put(const char ID,int val) {
  checkid(ID);
  if (m_valid) wait(m_changed);
  m_value = val;
  m_valid = true;
  m_changed.notify();
}//end Genghis::put

int Genghis::get(const char ID) {
  checkid(ID);
  if (!m_valid) wait(m_changed);
  m_valid = false;
  m_changed.notify();
  return m_value;
}//end Genghis::get

bool Genghis::nb_put(const char ID, int  val) {
  checkid(ID);
  if (m_valid) return false;
  m_value = val;
  m_valid = true;
  m_changed.notify();
  return true;
}//end Genghis::nb_put

bool Genghis::nb_get(const char ID, int& val) {
  checkid(ID);
  if (!m_valid) return false;
  val = m_value;
  m_valid = false;
  m_changed.notify();
  return true;
}//end Genghis::nb_get

inline bool Genghis::empty(const char ID) { return !m_valid; }

inline bool Genghis::full(const char ID)  { return  m_valid; }

inline void Genghis::checkid(const char ID) {
  if (ID == m_id) return;
  cout << "ERROR("
       << name()
       << "): ID mismatch"
       << endl;
  errors++;
}//end Genghis::checkid

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: Genghis.inc,v 1.1 2004/01/16 17:57:04 dcblack Exp $

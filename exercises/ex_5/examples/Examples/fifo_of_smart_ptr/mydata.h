#ifndef MYDATA_H
#define MYDATA_H
//BEGIN mydata.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   See fifo_of_ptr.h


class mydata {
  int m_data;
public:
  // Constructors
  mydata():m_data(0){}
  mydata(int d):m_data(d) {}
  // Access methods
  int data() {
    return m_data;
  }
  // Randomization
  mydata& rand() {
    m_data = std::rand();
    return *this;
  }
  // Assignment
  mydata& operator= (mydata& rhs) {
    m_data = rhs.m_data;
    return *this;
  }
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: mydata.h,v 1.2 2004/04/15 17:39:35 dcblack Exp $

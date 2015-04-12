#ifndef FUNCTION_TEMPLATE_H
#define FUNCTION_TEMPLATE_H
//BEGIN function_template.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   Example of a C++ templatized function.
//   Compute the distance between two Cartesian
//   points expressed with any data type that
//   supports addition, multiplication, and sqrt().
//
// NOTE: This does not require SystemC.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template <typename T>
T Distance(const T sx,const T sy, const T ex,const T ey) {
  T dx = (sx - ex);
  T dy = (sy - ey);
  return (T)sqrt(dx*dx + dy*dy);
}

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: function_template.h,v 1.2 2004/04/15 17:39:51 dcblack Exp $

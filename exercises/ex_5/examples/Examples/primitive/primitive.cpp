//BEGIN primitive.cpp (systemc)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See primitive.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "primitive.h"

void primitive::first_thread(void) {
  for (int i=0;i!=5;i++) {
    cout << "INFO: Put " << i << endl;
    khan.put('a',i);
  }//endfor
}//end primitive::first_thread

void primitive::second_thread(void) {
  int val;
  for (;;) {
    val = khan.get('a');
    cout << "INFO: Got " << val << endl;
  }//endforever
}//end primitive::second_thread

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: primitive.cpp,v 1.2 2004/02/02 12:46:14 dcblack Exp $

#ifndef OPCODES_H
#define OPCODES_H
//FILE: opcodes.h (systemc)
//# vim600:sw=2:tw=0:fdm=marker
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// See processor.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <string>
#include <sstream>
#include <iomanip>

enum constants {
  ALERT_ADDR = 0x1,
  ABORT_ADDR = 0x10,
  RESET_ADDR = 0x20,
  IMMED = 0,
  INDIR = 1
};
enum instruction {
  NOP,        // 
  ABORT,      //
  ALERT,      // value
  COMPARE,    // buffer
  CONVOLVE,   // buffer
  DECODE,     // buffer
  DECR,       //
  ENCODE,     // buffer
  HALT,       // condition
  INCR,       //
  JUMP,       // condition, addr
  LOAD_ACC,   // type, addr
  LOAD_BUFF,  // buff, addr
  SEARCH,     // buffer
  STORE_ACC,  // addr
  STORE_BUFF  // buff, addr
};
enum condition {
  NEVER=0,
  IF_PASS,
  IF_FAIL,
  ALWAYS
};
static const char* condition(unsigned n) {
  switch (n) {
  case NEVER:   return "NEVER";
  case ALWAYS:  return "ALWAYS";
  case IF_FAIL: return "IF_FAIL";
  case IF_PASS: return "IF_FAIL";
  }
}
static std::string disasm(
  unsigned pc,
  unsigned opcode,
  unsigned operand1,
  unsigned operand2
) {
  std::ostringstream mout;

  mout << std::setw(4) << std::setfill('0') << std::hex << pc;
  std::string result = mout.str();
  switch (opcode) {
    case NOP:
      mout.str("NOP");        
      result += mout.str();
      break;
    case ABORT:      
      mout.str("ABORT");
      result += mout.str();
      break;
    case ALERT: 
      mout << "ALERT" << std::setw(4) << std::setfill('0') << std::hex << operand1;
      result += mout.str();
      break;
    case CONVOLVE:  
      mout << "CONVOLVE" << std::dec << operand1; 
      result += mout.str();
      break;
    case DECODE:     
      mout << "DECODE" << std::dec << operand1;
      result += mout.str();
      break;
    case DECR: 
      mout.str("DECR");      
      result += mout.str();
      break; 
    case ENCODE:     
      mout << "ENCODE" << std::dec << operand1;
      result += mout.str();
      break;
    case HALT:      
      mout << "HALT" << condition(operand1); 
      result += mout.str();
       break;
    case INCR:      
      mout.str("INCR"); 
      result += mout.str();
      break;
    case JUMP:   
      mout << "JUMP" << condition(operand1) << std::hex << operand2;    
      result += mout.str();
      break;
    case LOAD_ACC:  
      mout << "LOAD_ACC " << ((operand1 == 0)?"IMMED":"INDIR")  << std::dec << operand2; 
      result += mout.str();
      break;
    case LOAD_BUFF:  
      mout << "LOAD_BUFF" << std::dec << operand1 << std::dec << operand2;
      result += mout.str();
      break;
    case SEARCH:     
      mout << "SEARCH" << std::dec << operand1;
      result += mout.str();
      break;
    case STORE_ACC:  
      mout << "STORE_ACC" << std::dec << operand1;
      result += mout.str();
      break;
    case STORE_BUFF: 
      mout << "STORE_BUFF" << std::dec << operand1 << std::dec << operand2;
      result += mout.str();
      break;
  }//endswitch
  return result;
}
#endif
//Portions COPYRIGHT (C) 2004 Eklectic Ally, Inc. DBA ESLX Inc.----{{{//
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//-----------------------------------------------------------------}}}//
//END $Id$

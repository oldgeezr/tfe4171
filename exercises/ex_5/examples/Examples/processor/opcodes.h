#ifndef OPCODES_H
#define OPCODES_H
//FILE: opcodes.h (systemc)
//# vim600:sw=2:tw=0:fdm=marker
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// See processor.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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
static char* condition(unsigned n) {
  switch (n) {
  case NEVER:   return "NEVER";
  case ALWAYS:  return "ALWAYS";
  case IF_FAIL: return "IF_FAIL";
  case IF_PASS: return "IF_FAIL";
  }
}
static sc_string disasm(
  unsigned pc,
  unsigned opcode,
  unsigned operand1,
  unsigned operand2
) {
  sc_string result = sc_string::to_string("%04x: ",pc);
  switch (opcode) {
    case NOP:        
      result += sc_string::to_string("NOP");
      break;
    case ABORT:      
      result += sc_string::to_string("ABORT");
      break;
    case ALERT:      
      result += sc_string::to_string("ALERT 0x%4x",operand1);
      break;
    case COMPARE:    
      result += sc_string::to_string("COMPARE %d",operand1);
      break;
    case CONVOLVE:   
      result += sc_string::to_string("CONVOLVE %d",operand1);
      break;
    case DECODE:     
      result += sc_string::to_string("DECODE %d",operand1);
      break;
    case DECR:       
      result += sc_string::to_string("DECR");
      break;
    case ENCODE:     
      result += sc_string::to_string("ENCODE %d",operand1);
      break;
    case HALT:       
      result += sc_string::to_string("HALT %s",condition(operand1));
      break;
    case INCR:       
      result += sc_string::to_string("INCR");
      break;
    case JUMP:       
      result += sc_string::to_string("JUMP %s 0x%4x",condition(operand1),operand2);
      break;
    case LOAD_ACC:   
      result += sc_string::to_string("LOAD_ACC %s %d",(operand1==0?"IMMED":"INDIR"),operand2);
      break;
    case LOAD_BUFF:  
      result += sc_string::to_string("LOAD_BUFF %d, %d",operand1,operand2);
      break;
    case SEARCH:     
      result += sc_string::to_string("SEARCH %d",operand1);
      break;
    case STORE_ACC:  
      result += sc_string::to_string("STORE_ACC %d",operand1);
      break;
    case STORE_BUFF: 
      result += sc_string::to_string("STORE_BUFF %d, %d",operand1,operand2);
      break;
  }//endswitch
  return result;
}
#endif
//Portions COPYRIGHT (C) 2004 Eklectic Ally, Inc.------------------{{{//
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//-----------------------------------------------------------------}}}//
//END $Id: opcodes.h,v 1.2 2004/04/15 17:43:49 dcblack Exp $

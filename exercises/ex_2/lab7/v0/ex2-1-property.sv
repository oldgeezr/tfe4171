/*
 * Turning all checks on with check5
 */
`ifdef check5
`define check1
`define check2
`define check3
`define check4
`endif

module ex2_1_property
  (
   input 	      clk, rst, validi,
   input [31:0]       data_in,
   input logic 	      valido,
   input logic [31:0] data_out
   );

/*------------------------------------
 *
 *        CHECK # 1. Check that when 'rst' is asserted (==1) that data_out == 0
 *
 *------------------------------------ */

`ifdef check1
/* -----\/----- EXCLUDED -----\/-----

property reset_asserted;
   @(posedge clk) rst |=> data_out=0;
endproperty

reset_check: assert property(reset_asserted)
  $display($stime,,,"\t\tRESET CHECK PASS:: rst_=%b data_out=%0d \n",
	   rst, data_out);
else $display($stime,,,"\t\RESET CHECK FAIL:: rst_=%b data_out=%0d \n",
	      rst, data_out);
 -----/\----- EXCLUDED -----/\-----  */
`endif

/* ------------------------------------
 * Check valido assertion to hold
 *
 *       CHECK # 2. Check that valido is asserted when validi=1 for three
 *                  consecutive clk cycles
 *
 * ------------------------------------ */

`ifdef check2
property validi3_asserted;
   @(posedge clk) validi[*3] |-> ##1 valido;
endproperty

validi3_check: assert property(validi3_asserted)
  $display($stime,,,"\t\tVALIDI3 CHECK PASS:: validi=%b valido=%b \n",
  validi, valido);
else $display($stime,,,"\t\tVALIDI3 CHECK FAIL:: validi=%b valido=%b \n",
  validi, valido);
`endif

/* ------------------------------------
 * Check valido not asserted wrong
 *
 *       CHECK # 3. Check that valido is not asserted when validi=1 for only two, one
 *                  or zero consecutive clk cycles
 *
 * ------------------------------------ */

`ifdef check3
property validi2_asserted;
  @(posedge clk) $rose(validi) ##0 validi[*0:2] ##1 $fell(validi) |-> !valido;
endproperty

validi2_check: assert property(validi2_asserted)
  $display($stime,,,"\t\tVALIDI2 CHECK PASS:: validi=%b valido=%b \n",
  validi, valido);
else $display($stime,,,"\t\tVALIDI2 CHECK FAIL:: validi=%b valido=%b \n",
  validi, valido);
`endif

/* ------------------------------------
 * Check data_out value
 *
 *       CHECK # 4. Check that data_out when valido=1 is equal to a*b+c where a is data_in
 *       two cycles back, b is data_in one cycle back, and c is the present data_in
 *
 * ------------------------------------ */

sequence seq_a;
  validi[*1];
endsequence

sequence seq_aa;
  validi[*1] ##0 $fell(validi);
endsequence

sequence seq_b;
  validi[*2];
endsequence

sequence seq_c;
  validi[*3];
endsequence

sequence seq_complete;
  validi[*3] ##0 $fell(validi);
endsequence

sequence check_a;
  int a;
  int b;
  int c;
  (seq_a, a=data_in) ##1 (seq_a, b=data_in) ##1 (seq_a, c=data_in) ##1 (data_out == (a*b + c));
  // (seq_complete, a=data_in) ##1 (seq_complete, b=data_in) ##1 (seq_complete, c=data_in) ##1 (data_out == (a*b + c));
  // (seq_a, a=data_in) ##0 (seq_a, b=data_in) ##0 (seq_c, c=data_in) ##1 (data_out == (a*b + c));
endsequence

`ifdef check4
property validi2_asserted;
  @(posedge clk) $rose(validi) |-> check_a;
endproperty

validi2_check: assert property(validi2_asserted)
  $display($stime,,,"\t\tDATAOUT CHECK PASS::");
else $display($stime,,,"\t\tDATAOUT CHECK FAIL::");
`endif

endmodule

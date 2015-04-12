module symmetric_fir(COEFF, DI, DQ, YI, YQ, LD, CLK, RST);
  parameter WIDTH = 12;
  parameter TAPS = 31;
  parameter INITIATION = 4;
  parameter TAP_BITS = 5;
  input [WIDTH-1:0] COEFF, DI, DQ;
  output LD;                            reg LD;
  output [2*WIDTH+TAP_BITS-1:0] YI, YQ; reg [2*WIDTH+TAP_BITS-1:0] YI, YQ;
  input CLK;
  input RST;

  reg [WIDTH-1:0] C,I,Q [0:TAPS-1];
  reg [2*WIDTH+TAP_BITS-1:0] SI, SQ;

  always begin :BEHAVIOR
    LD <= 1'd1;
    @(posedge CLK); if (RST) disable BEHAVIOR;
    //--------------------------------------------
    // initialize coefficients
    //--------------------------------------------
    for (i=0; i<=TAPS; i=i+1) begin
      C[i] <= COEFF;
      I[i] <= DI;
      Q[i] <= DQ;
      if (i == TAPS) LD <= 1'd0;
      @(posedge CLK); if (RST) disable BEHAVIOR;
    end
    forever begin :FILTER
      //------------------------------------------
      // Compute output
      //------------------------------------------
      SI = 0;
      SQ = 0;
      for (i=0; i<(TAPS/2); i=i+1) begin
        SI = SI + C[i] * (I[i] + I[TAPS-1-i]);
        SQ = SQ + C[i] * (Q[i] + Q[TAPS-1-i]);
      end
      if (TAPS & 1'b1) begin //NOTE: This should optimize away for even TAPS
        YI = YI + C[TAPS/2] * I[TAPS/2];
        YQ = YQ + C[TAPS/2] * Q[TAPS/2];
      end
      YI <= SI;
      YQ <= SQ;
      //------------------------------------------
      // update taps
      //------------------------------------------
      for (i=0; i<TAPS; i=i+1) begin
        I[i] <= I[i+1];
        Q[i] <= Q[i+1];
      end
      I[TAPS-1] <= DI;
      Q[TAPS-1] <= DQ;
      repeat (INITIATION) @(posedge CLK); if (RST) disable BEHAVIOR;
    end //forever FILTER
  end //always BEHAVIOR
endmodule //symmetric_fir

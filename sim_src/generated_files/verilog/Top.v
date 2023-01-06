module Bypass(
  input  [15:0] io_inValue,
  output [15:0] io_outValue
);
  assign io_outValue = io_inValue; // @[Bypass.scala 9:15]
endmodule
module Top(
  input         clock,
  input         reset,
  input  [15:0] io_value1,
  input  [15:0] io_value2,
  input         io_loadingValues,
  output [15:0] io_outputGCD,
  output        io_outputValid
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
  wire [15:0] byPassX_io_inValue; // @[Top.scala 24:25]
  wire [15:0] byPassX_io_outValue; // @[Top.scala 24:25]
  wire [15:0] byPassY_io_inValue; // @[Top.scala 27:25]
  wire [15:0] byPassY_io_outValue; // @[Top.scala 27:25]
  reg [15:0] x; // @[Top.scala 14:14]
  reg [15:0] y; // @[Top.scala 15:14]
  wire [15:0] _x_T_1 = x - y; // @[Top.scala 18:12]
  wire [15:0] _y_T_1 = y - x; // @[Top.scala 20:12]
  Bypass byPassX ( // @[Top.scala 24:25]
    .io_inValue(byPassX_io_inValue),
    .io_outValue(byPassX_io_outValue)
  );
  Bypass byPassY ( // @[Top.scala 27:25]
    .io_inValue(byPassY_io_inValue),
    .io_outValue(byPassY_io_outValue)
  );
  assign io_outputGCD = x; // @[Top.scala 32:18]
  assign io_outputValid = y == 16'h0; // @[Top.scala 33:23]
  assign byPassX_io_inValue = io_value1; // @[Top.scala 25:24]
  assign byPassY_io_inValue = io_value2; // @[Top.scala 28:24]
  always @(posedge clock) begin
    if (io_loadingValues) begin // @[Top.scala 23:26]
      x <= byPassX_io_outValue; // @[Top.scala 26:24]
    end else if (x > y) begin // @[Top.scala 17:15]
      x <= _x_T_1; // @[Top.scala 18:7]
    end
    if (io_loadingValues) begin // @[Top.scala 23:26]
      y <= byPassY_io_outValue; // @[Top.scala 29:24]
    end else if (!(x > y)) begin // @[Top.scala 17:15]
      y <= _y_T_1; // @[Top.scala 20:7]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  x = _RAND_0[15:0];
  _RAND_1 = {1{`RANDOM}};
  y = _RAND_1[15:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule

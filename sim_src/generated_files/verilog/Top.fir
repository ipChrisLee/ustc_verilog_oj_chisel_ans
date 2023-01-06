circuit Top :
  module Bypass :
    input clock : Clock
    input reset : Reset
    output io : { flip inValue : UInt<16>, outValue : UInt<16>}

    io.outValue <= io.inValue @[Bypass.scala 9:15]

  module Bypass_1 :
    input clock : Clock
    input reset : Reset
    output io : { flip inValue : UInt<16>, outValue : UInt<16>}

    io.outValue <= io.inValue @[Bypass.scala 9:15]

  module Top :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip value1 : UInt<16>, flip value2 : UInt<16>, flip loadingValues : UInt<1>, outputGCD : UInt<16>, outputValid : UInt<1>}

    reg x : UInt, clock with :
      reset => (UInt<1>("h0"), x) @[Top.scala 14:14]
    reg y : UInt, clock with :
      reset => (UInt<1>("h0"), y) @[Top.scala 15:14]
    node _T = gt(x, y) @[Top.scala 17:10]
    when _T : @[Top.scala 17:15]
      node _x_T = sub(x, y) @[Top.scala 18:12]
      node _x_T_1 = tail(_x_T, 1) @[Top.scala 18:12]
      x <= _x_T_1 @[Top.scala 18:7]
    else :
      node _y_T = sub(y, x) @[Top.scala 20:12]
      node _y_T_1 = tail(_y_T, 1) @[Top.scala 20:12]
      y <= _y_T_1 @[Top.scala 20:7]
    when io.loadingValues : @[Top.scala 23:26]
      inst byPassX of Bypass @[Top.scala 24:25]
      byPassX.clock <= clock
      byPassX.reset <= reset
      byPassX.io.inValue <= io.value1 @[Top.scala 25:24]
      x <= byPassX.io.outValue @[Top.scala 26:24]
      inst byPassY of Bypass_1 @[Top.scala 27:25]
      byPassY.clock <= clock
      byPassY.reset <= reset
      byPassY.io.inValue <= io.value2 @[Top.scala 28:24]
      y <= byPassY.io.outValue @[Top.scala 29:24]
    io.outputGCD <= x @[Top.scala 32:18]
    node _io_outputValid_T = eq(y, UInt<1>("h0")) @[Top.scala 33:23]
    io.outputValid <= _io_outputValid_T @[Top.scala 33:18]


circuit Top :
  module Top :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip value1 : UInt<16>, flip value2 : UInt<16>, flip loadingValues : UInt<1>, outputGCD : UInt<16>, outputValid : UInt<1>}

    reg x : UInt, clock with :
      reset => (UInt<1>("h0"), x) @[Top.scala 13:14]
    reg y : UInt, clock with :
      reset => (UInt<1>("h0"), y) @[Top.scala 14:14]
    node _T = gt(x, y) @[Top.scala 16:10]
    when _T : @[Top.scala 16:15]
      node _x_T = sub(x, y) @[Top.scala 17:12]
      node _x_T_1 = tail(_x_T, 1) @[Top.scala 17:12]
      x <= _x_T_1 @[Top.scala 17:7]
    else :
      node _y_T = sub(y, x) @[Top.scala 19:12]
      node _y_T_1 = tail(_y_T, 1) @[Top.scala 19:12]
      y <= _y_T_1 @[Top.scala 19:7]
    when io.loadingValues : @[Top.scala 22:26]
      x <= io.value1 @[Top.scala 23:6]
      y <= io.value2 @[Top.scala 24:6]
    io.outputGCD <= x @[Top.scala 27:18]
    node _io_outputValid_T = eq(y, UInt<1>("h0")) @[Top.scala 28:23]
    io.outputValid <= _io_outputValid_T @[Top.scala 28:18]


package top
import chisel3._
import bypass.Bypass

class Top extends Module {
  val io = IO(new Bundle {
    val value1        = Input(UInt(16.W))
    val value2        = Input(UInt(16.W))
    val loadingValues = Input(Bool())
    val outputGCD     = Output(UInt(16.W))
    val outputValid   = Output(Bool())
  })

  val x = Reg(UInt())
  val y = Reg(UInt())

  when(x > y) {
    x := x - y
  }.otherwise {
    y := y - x
  }

  when(io.loadingValues) {
    val byPassX = Module(new Bypass())
    byPassX.io.inValue := io.value1
    x                  := byPassX.io.outValue
    val byPassY = Module(new Bypass())
    byPassY.io.inValue := io.value2
    y                  := byPassY.io.outValue
  }

  io.outputGCD   := x
  io.outputValid := y === 0.U
}

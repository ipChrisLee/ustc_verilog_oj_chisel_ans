package answers
import chisel3._
import chisel3.util._

class mod_a extends BlackBox {
  val io = IO(new Bundle {
    val in1 = Input(Bool())
    val in2 = Input(Bool())
    val out = Output(Bool())
  })
}

class P0143 extends RawModule {
  val a   = IO(Input(Bool()))
  val b   = IO(Input(Bool()))
  val out = IO(Output(Bool()))
  val m   = Module(new mod_a)
  m.io.in1 := a
  m.io.in2 := b
  out      := m.io.out
}

package answers
import chisel3._
import chisel3.util._

class P0097 extends RawModule {
  val clk = IO(Input(Clock()))
  val in  = IO(Input(Bool()))
  val out = IO(Output(Bool()))

  withClock(clk) {
//  withClockAndReset(clk, rst) {
    val s0 :: s1 :: s2 :: Nil = Enum(3)
    val state                 = Reg(UInt(2.W))
    when(state === s0) {
      state := Mux(in, s1, s0)
    }.elsewhen(state === s1) {
      state := s2
    }.elsewhen(state === s2) {
      state := Mux(in, s2, s0)
    }.otherwise {
      state := 0.U
    }
    out := state === s1
  }

}

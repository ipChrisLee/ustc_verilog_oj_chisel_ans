package answers
import chisel3._
import chisel3.util._

class P0070 extends RawModule {
  val clk   = IO(Input(Clock()))
  val reset = IO(Input(Bool()))
  val en    = IO(Input(Bool()))
  val q     = IO(Output(UInt(4.W)))
  withClockAndReset(clk, reset) {
    val r = RegInit(5.U(4.W))
    r := Mux(
      en,
      Mux(r === 5.U, 15.U, r - 1.U),
      r
    )
    q := r
  }
}

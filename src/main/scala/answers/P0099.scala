package answers
import chisel3._
import chisel3.util._

class P0099 extends RawModule {
  val clk   = IO(Input(Clock()))
  val reset = IO(Input(Bool()))
  val ss    = IO(Output(UInt(8.W)))

  withClockAndReset(clk, reset) {
    val count = Counter(4)
    count.inc()
    val counter = RegInit(0.U(8.W))
    counter := counter + count.value.andR
    ss      := Cat((counter / 10.U(4.W))(7, 4), (counter % 10.U(4.W)(3, 0)))
  }
}

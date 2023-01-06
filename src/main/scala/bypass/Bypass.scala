package bypass
import chisel3._

class Bypass extends Module {
  val io = IO(new Bundle {
    val inValue  = Input(UInt(16.W))
    val outValue = Output(UInt(16.W))
  })
  io.outValue := io.inValue
}

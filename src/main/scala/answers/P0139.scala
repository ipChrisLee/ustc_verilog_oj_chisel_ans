package answers

import chisel3._
import chisel3.util._

class P0139 extends RawModule {
  val in  = IO(Input(UInt(4.W)))
  val pos = IO(Output(UInt(2.W)))
  //  val r   = RegInit(0.U(pos.getWidth))
  pos := Mux(in.orR, PriorityEncoder(in), 0.U)

}

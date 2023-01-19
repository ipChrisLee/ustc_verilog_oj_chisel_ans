package answers
import chisel3._
import chisel3.util._

class Muxer extends Module {
  val io = IO(new Bundle {
    val sel = Input(Bool())
    val inT = Input(UInt(4.W))
    val inF = Input(UInt(4.W))
    val out = Output(UInt(4.W))
  })
  io.out := Mux(io.sel, io.inT, io.inF)
}

class P0078 extends RawModule {
  val clk   = IO(Input(Clock()))
  val reset = IO(Input(Bool()))
  val q     = IO(Output(UInt(4.W)))

  withClockAndReset(clk, reset) {
    val r     = RegInit(1.U(4.W))
    val muxer = Module(new Muxer)
    muxer.io.sel := r === 10.U
    muxer.io.inT := 1.U
    muxer.io.inF := r + 1.U
    r            := muxer.io.out
    q            := r
  }
}

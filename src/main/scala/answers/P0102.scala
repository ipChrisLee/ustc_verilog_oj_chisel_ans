package answers

import chisel3._
import chisel3.util._

class P0102 extends RawModule {
  val clk    = IO(Input(Clock()))
  val areset = IO(Input(Bool()))
  val in     = IO(Input(Bool()))
  val out    = IO(Output(Bool()))

  withClockAndReset(clk, areset.asAsyncReset) {
    val a :: b :: Nil = Enum(2)
    val state         = RegInit(b)
    val tran = Array(
      a -> Array(
        0 -> b,
        1 -> a
      ),
      b -> Array(
        0 -> a,
        1 -> b
      )
    )
    state := MuxLookup(
      state,
      0.U,
      tran.collect {
        case s =>
          s._1 -> MuxLookup(
            in,
            0.U,
            s._2.collect {
              case e => e._1.U -> e._2
            }.toIndexedSeq
          )
      }.toIndexedSeq
    )
    out := MuxLookup(
      state,
      0.U,
      Array(
        a -> 0.U,
        b -> 1.U
      ).toIndexedSeq
    )
  }
}

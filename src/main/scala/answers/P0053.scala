package answers
import chisel3._
import chisel3.util._

class P0053 extends RawModule {
  val a = IO(Input(UInt(5.W)))
  val b = IO(Input(UInt(5.W)))
  val c = IO(Input(UInt(5.W)))
  val d = IO(Input(UInt(5.W)))
  val e = IO(Input(UInt(5.W)))
  val f = IO(Input(UInt(5.W)))

  val w = IO(Output(UInt(8.W)))
  val x = IO(Output(UInt(8.W)))
  val y = IO(Output(UInt(8.W)))
  val z = IO(Output(UInt(8.W)))

  val m = Cat(a, b, c, d, e, f, "b11".U(2.W))
  w := m(31, 24)
  x := m(23, 16)
  y := m(15, 8)
  z := m(7, 0)
}

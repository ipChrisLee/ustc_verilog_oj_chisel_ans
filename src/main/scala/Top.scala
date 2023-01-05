import chisel3._
import gcd.GCD
object Top extends App{
  (new chisel3.stage.ChiselStage).emitVerilog(new GCD, args)
}

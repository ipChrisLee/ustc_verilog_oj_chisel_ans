package answers
import chisel3._
import chisel3.util._

//  https://verilogoj.ustc.edu.cn/oj/problem/30
class P0030 extends RawModule {
  val out = IO(Output(Bool()))
  out := 1.B

}

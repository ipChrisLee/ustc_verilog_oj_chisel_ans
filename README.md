此为[USTC-VerilogOJ](https://verilogoj.ustc.edu.cn/oj/problem/30)的Chisel模板仓库。

src/main/scala/answers/P0030和P0078是[https://verilogoj.ustc.edu.cn/oj/problem/30](https://verilogoj.ustc.edu.cn/oj/problem/30)和[https://verilogoj.ustc.edu.cn/oj/problem/78](https://verilogoj.ustc.edu.cn/oj/problem/78)的代码。

作业过程：

1. 在src/main/scala/answers下新建Scala文件，**文件名或者说类名随意**。

2. 实现电路。

   根据目前测试：

   * 提交的module的输入输出信号需要同名。
   * 但是不需要同种类。比如0078里，官方代码给的输出是`output reg [3:0] q`，但是我们的会生成`output [3:0] q`，根据测试这个不会导致不通过。
   * 允许提交的代码里有多个module（但是顶层module名必须是`top_module`，这个限制我们通过别的方式保证了，所以你可以随意命名你的类）。

   举个例子，如果OJ给的代码是：

   ```verilog
   module top_module (
       input 				clk		,	//时钟信号
       input 				reset	,   //同步高电平有效复位信号
       output reg 	[3:0] 	q			//计数结果
   );
   // 请用户在下方编辑代码
   
   
   
   //用户编辑到此为止 
   endmodule
   ```

   你就需要在模型中给：

   * 名为`clk`的宽度为1的`input`。
   * 名为`reset`的宽度为1的`input`。
   * 名为`q`的宽度为4的`output`。

   所以你的Chisel应该这么写：

   ```scala
   class P0078 extends RawModule {
       val clk = IO(Input(Clock()))
       val reset = IO(Input(Bool()))
       val q = IO(Output(UInt(4.W)))
       //	implement this
   }
   ```

   值得注意的是：

   * 与一般的`extends Module`不同，这里建议`extends RawModule`，这样可以避免Chisel帮你生成时钟信号和复位信号，进而导致你使用了Chisel生成的时钟信号和复位信号，而不是`clk`和`reset`。

   * 这里的`clk`是时钟信号，可以直接使用`Clock()`类型。当然你写`IO(Input(Bool()))`也行，但是这样的话你可能需要在`withClock`中写`withClock(clk.asClock)`而不是`withClock(clk)`。

   * 这里的`q`并不是Verilog中的寄存器，这是因为Chisel中`IO`不能是个`Reg`。

   * 正如前面提到的，你的`P0078`是一个`RawModule`，没有默认时钟，所以直接写`val r = RegInit(UInt(4.W))`是不行的，建议写：

     ```scala
     withClockAndReset(clk, reset){
     	val r = RegInit(UInt(4.W))
     }
     ```

3. 更改src/main/scala/TopApp里`top_module`继承（或者说`extends`）的类为你刚完成的类。

4. 在项目根目录运行`sbt "runMain TopApp --target-dir verilog_gen"`，将生成的`verilog_gen/top_module.v`提交到OJ。

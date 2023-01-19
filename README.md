此为[USTC-VerilogOJ](https://verilogoj.ustc.edu.cn/oj/problem/30)的Chisel模板仓库。

src/main/scala/answers/P0030和P0078是[https://verilogoj.ustc.edu.cn/oj/problem/30](https://verilogoj.ustc.edu.cn/oj/problem/30)和[https://verilogoj.ustc.edu.cn/oj/problem/78](https://verilogoj.ustc.edu.cn/oj/problem/78)的代码。

作业过程：

1. 在src/main/scala/answers下新建Scala文件，**文件名或者说类名随意**。

2. 实现电路。

   根据目前测试：

   * 提交的module的输入输出信号需要同名。
   * 但是不需要同种类。比如0078里，官方代码给的输出是`output reg [3:0] q`，但是我们的会生成`output [3:0] q`，根据测试这个不会导致不通过。
   * 允许提交的代码里有多个module（但是顶层module名必须是`top_module`，这个限制我们通过别的方式保证了，所以你可以随意命名你的类）。

3. 更改src/main/scala/TopApp里`top_module`继承（或者说`extends`）的类为你刚完成的类。

4. 在项目根目录运行`sbt "runMain TopApp --target-dir verilog_gen"`，将生成的`verilog_gen/top_module.v`提交到OJ。

 建议搜索问题ID来看，否则容易瞟到解析。

无剧透、小吐槽版本（难度为个人感受，不是OJ的）：

* 入门

  * [P0030**输出1**](https://verilogoj.ustc.edu.cn/oj/problem/30)

  * [P0078**十进制计数器**](https://verilogoj.ustc.edu.cn/oj/problem/78)

  * [P0053**向量拼接**](https://verilogoj.ustc.edu.cn/oj/problem/53)

    Chisel好像没有很方便的向量拼接的东西。。。

  * [P0143**模块例化**](https://verilogoj.ustc.edu.cn/oj/problem/143)

    签到题，主要是为了在VerilogOJ上交这题的Chisel代码需要写一个`BlackBox`，值得注意下。

  * [P0070**带使能的计数器**](https://verilogoj.ustc.edu.cn/oj/problem/70)

    论Mux的使用。

* 进阶

  * [P0102**有限状态机**](https://verilogoj.ustc.edu.cn/oj/problem/102)

    《论Chisel的有限状态机有几种写法》。

    实际上这题也可以不用这种鬼畜的写法。

* 困难（可能）

  * [P0097**上升沿检测**](https://verilogoj.ustc.edu.cn/oj/problem/97)

    这题槽点挺多的。



后面是一些题的解析

### [P0097**上升沿检测**](https://verilogoj.ustc.edu.cn/oj/problem/97)

这题从Chisel看槽点挺多的：

* 不给复位信号，只能在提交的时候手写一个类似`initial state = 2'b00;`的东西。

* 因为Chisel的时钟只能有一个，所以个人认为，如果题目的`in`呆在高电平的时间可能小于一个`clk`周期，那就不好弄了（此时是需要两个时钟信号控制一个寄存器，但是对于Chisel来说这事不太好办）。

  换句话说，“当in信号从0变为1时（相对于clk，该信号变化频率很慢）”很重要。

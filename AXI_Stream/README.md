# Axi_stream

## Module

```Verilog
    module axi_stream_insert_header #(
        parameter DATA_WD = 32,
        parameter DATA_BYTE_WD = DATA_WD / 8
    ) (
        input                        clk,
        input                        rst_n,
    
        // AXI Stream input original data
        input                        valid_in,
        input   [DATA_WD-1 : 0]      data_in,
        input   [DATA_BYTE_WD-1 : 0] keep_in,
        input                        last_in,
        output                       ready_in,
    
        // AXI Stream output with header inserted
        output                       valid_out,
        output  [DATA_WD-1 : 0]      data_out,
        output  [DATA_BYTE_WD-1 : 0] keep_out,
        output                       last_out,
        input                        ready_out,
    
        // The header to be inserted to AXI Stream input
        input                        valid_insert,
        input   [DATA_WD-1 : 0]      header_insert,
        input   [DATA_BYTE_WD-1 : 0] keep_insert,
        output                       ready_insert
    );
```

### Inputs

data输入通道：
+ data_in: 代表多字节输入数据，data_in_width = byte_numbers * 8，其中byte_numbers为2的整数次幂
+ keep_in: 代表一拍中多少字节是有效的，1为有效字节，0为无效字节，keep_in的长度为byte_numbers；除了最后一拍(即last_in有效)的数据中keep_in存在无效字节外，其余数据输入均有效；keep_in可能的数值为`4'b1111`, `4'b1110`, `4'b1100`, `4'b1000`
+ last_in: Axi_stream最后一组输入数据的data_in的标识位

header输入通道：
+ header_insert: 代表多字节头包输入数据，位宽定义与data_in一致
+ keep_insert:代表header输入通道中多少字节所有效的，与data输入通道中末尾数据无效不同，header是开头若干字节会无效，其取值范围有`4'b1111`, `4'b0111`, `4'b0011`, `4'b0001`

### Outputs

+ data_out: 代表多字节输出数据，输出位宽与data_in相同
+ keep_out: 用于标识data_out输出中的有效字节；除了最后一拍(即last_in有效)的数据中keep_out存在无效字节外，其余数据输入均有效；keep_out可能的数值为`4'b1111`, `4'b1110`, `4'b1100`, `4'b1000`
+ last_out: Axi_stream最后一组输出数据的data_in的标识位

## Requirements

+ 输入两路AXI Stream信号，分别是head输入和data输入，输出一路AXI Stream信号
+ 每个data输入可能有多拍，每个header输入只有一拍，需要对data和head输入数据做拼接处理

## Example

输入:
+ 一拍header_insert：`32'hFEDC`；
+ 一拍keep_insert：`4'b0111`；
+ 五拍data_in分别是：`32'hABCD`, `32'hEF01`, `32'h2345`, `32'h6789`, `32'h0AXX`(X代表任意值)；
+ 五拍last_in分别是：`1'b0`, `1'b0`, `1'b0`, `1'b0`, `1'b1`；
+ 五拍keep_in分别是：`4'b1111`, `4'b1111`, `4'b1111`, `4'b1111`， `4'b1100`；

输出:
- 六拍data_in分别是：`32'hEDCA`, `32'hBCDE`, `32'hF012`, `32'h3456`, `32'h7890`, `32'hAXXX`；
- 六拍last_in分别是：`1'b0`, `1'b0`, `1'b0`, `1'b0`, `1'b0`, `1'b1`；
- 六拍keep_in分别是：`4'b1111`, `4'b1111`, `4'b1111`, `4'b1111`， `4'b1111`， `4'b1000`。

## Verification

### Framework

```
    ┌──────┐    ┌───────────────┐
    │ Test ├────►   Reference   ├───────┐
    │ Case │    │   Model       │       │
    └───┬──┘    └───────────────┘       │
        │                               │
    ┌───▼────┐  ┌───────────────┐  ┌────▼───┐
    │        │  │               │  │        │
    │ Input  ├──►      DUT      ├──► Output │
    │ Driver │  │               │  │ Driver │
    │        │  │               │  │        │
    └────────┘  └──────▲────────┘  └────────┘
                        │
                    ┌───┴─────┐
                    │ Clock/  │
                    │ Reset   │
                    └─────────┘
```

### Utilization

#### Set DUT in Makefile

```Makefile
    VERILOG_SOURCES += $(PWD)/axi_stream_insert_header.v
```

#### Initialize Axi-Stream Tb

```Python
    class axiStreamTb(object):
        def __init__(self, dut):
        self.dut = dut
        self.inDriver = inputDriver(dut.clk, dut.valid_in, dut.data_in, dut.keep_in, dut.last_in, dut.ready_out, dut.valid_insert, dut.header_insert, dut.keep_insert, dut.ready_in, dut.ready_insert)
        self.outputMonitor = outputMonitor(dut.clk, dut.valid_out, dut.ready_out, dut.data_out, dut.keep_out, dut.last_out)
        self.clockCtrl = clockDomain(self.dut.clk, 10, "ns", self.dut.rst_n, False)
```

#### Start Test

```Python
    tb = axiStreamTb(dut)
        await tb.start()
```

#### Initialize Header

```Python
    headData = headerStream(int("12345678", 16), "0011")
    tb.addTransaction(headData)
```

#### Deploy Data

```Python
    for i in range(5):
        randData = genRandomData()
        tb.addTransaction(dataStream(randData))
```

#### Deploy Last Data

```Python
    tb.addTransaction(lastStream(genRandomData(), "1100"))
```

#### Waiting Finish & Checking Outputs

```Python
    await tb.waitAllDone()
    tb.resultCheck()
```

#### Stop Test

```Python
    tb.stop()
```

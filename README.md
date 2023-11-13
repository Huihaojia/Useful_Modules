# Useful_Modules
This repo collects several implementation of comman and useful hardware modules.

## Contents

### Handshake Protocol

+ Three types of handshake protocl is realized using Verilog, including valid-stream, ready-stream, and valid & ready stream. Waveform diagram is also illustrated.
+ Three types of FIFO is realized using BlueSpec, including Pipeline FIFO, Bypass FIFO, and Conflict Free FIFO.

### AXI Stream

+ A simple AXI-Stream is realized using Verilog. This realization can insert header before data transfer and squeeze out Null bytes during every transfer.
+ A simple UVM is also realized under cocotb framework. Several utilization is available to build a axi-stream test.
module testbench ();

    reg clk, rst;
    reg in_fifo_valid_in0, out_fifo_ready_in0;
    reg [15:0] in_fifo_data_in0;

    wire in_fifo_valid_out0, in_fifo_ready_out0, in_fifo_ready_in0,
        out_fifo_valid_in0, out_fifo_valid_out0, out_fifo_ready_out0;
    wire [15:0] in_fifo_data_out0, out_fifo_data_in0, out_fifo_data_out0;

    reg in_fifo_valid_in1, out_fifo_ready_in1;
    reg [15:0] in_fifo_data_in1;

    wire in_fifo_valid_out1, in_fifo_ready_out1, in_fifo_ready_in1,
        out_fifo_valid_in1, out_fifo_valid_out1, out_fifo_ready_out1;
    wire [15:0] in_fifo_data_out1, out_fifo_data_in1, out_fifo_data_out1;

    reg in_fifo_valid_in2, out_fifo_ready_in2;
    reg [15:0] in_fifo_data_in2;

    wire in_fifo_valid_out2, in_fifo_ready_out2, in_fifo_ready_in2,
        out_fifo_valid_in2, out_fifo_valid_out2, out_fifo_ready_out2;
    wire [15:0] in_fifo_data_out2, out_fifo_data_in2, out_fifo_data_out2;

    reg_both_pip #(
        .DEPTH(4)
    ) U0 (
        .clk(clk),
        .rst(rst),
        .master_valid_in(in_fifo_valid_out0),
        .master_data_in(in_fifo_data_out0),
        .slave_ready_in(out_fifo_ready_out0),
        .master_valid_out(out_fifo_valid_in0),
        .master_data_out(out_fifo_data_in0),
        .slave_ready_out(in_fifo_ready_in0)
    );

    reg_valid_pip #(
        .DEPTH(4)
    ) U1 (
        .clk(clk),
        .rst(rst),
        .master_valid_in(in_fifo_valid_out1),
        .master_data_in(in_fifo_data_out1),
        .slave_ready_in(out_fifo_ready_out1),
        .master_valid_out(out_fifo_valid_in1),
        .master_data_out(out_fifo_data_in1),
        .slave_ready_out(in_fifo_ready_in1)
    );

    reg_ready_pip #(
        .DEPTH(4)
    ) U2 (
        .clk(clk),
        .rst(rst),
        .master_valid_in(in_fifo_valid_out2),
        .master_data_in(in_fifo_data_out2),
        .slave_ready_in(out_fifo_ready_out2),
        .master_valid_out(out_fifo_valid_in2),
        .master_data_out(out_fifo_data_in2),
        .slave_ready_out(in_fifo_ready_in2)
    );

    my_fifo #(
        .DEPTH(64)
    ) in_fifo0 (
        .clk(clk),
        .rst(rst),
        .valid_in(in_fifo_valid_in0),
        .ready_in(in_fifo_ready_in0),
        .data_in(in_fifo_data_in0),
        .valid_out(in_fifo_valid_out0),
        .ready_out(in_fifo_ready_out0),
        .data_out(in_fifo_data_out0)
    );

    my_fifo #(
        .DEPTH(4)
    ) out_fifo0 (
        .clk(clk),
        .rst(rst),
        .valid_in(out_fifo_valid_in0),
        .ready_in(out_fifo_ready_in0),
        .data_in(out_fifo_data_in0),
        .valid_out(out_fifo_valid_out0),
        .ready_out(out_fifo_ready_out0),
        .data_out(out_fifo_data_out0)
    );

    my_fifo #(
        .DEPTH(64)
    ) in_fifo1 (
        .clk(clk),
        .rst(rst),
        .valid_in(in_fifo_valid_in1),
        .ready_in(in_fifo_ready_in1),
        .data_in(in_fifo_data_in1),
        .valid_out(in_fifo_valid_out1),
        .ready_out(in_fifo_ready_out1),
        .data_out(in_fifo_data_out1)
    );

    my_fifo #(
        .DEPTH(4)
    ) out_fifo1 (
        .clk(clk),
        .rst(rst),
        .valid_in(out_fifo_valid_in1),
        .ready_in(out_fifo_ready_in1),
        .data_in(out_fifo_data_in1),
        .valid_out(out_fifo_valid_out1),
        .ready_out(out_fifo_ready_out1),
        .data_out(out_fifo_data_out1)
    );

    my_fifo #(
        .DEPTH(64)
    ) in_fifo2 (
        .clk(clk),
        .rst(rst),
        .valid_in(in_fifo_valid_in2),
        .ready_in(in_fifo_ready_in2),
        .data_in(in_fifo_data_in2),
        .valid_out(in_fifo_valid_out2),
        .ready_out(in_fifo_ready_out2),
        .data_out(in_fifo_data_out2)
    );

    my_fifo #(
        .DEPTH(4)
    ) out_fifo2 (
        .clk(clk),
        .rst(rst),
        .valid_in(out_fifo_valid_in2),
        .ready_in(out_fifo_ready_in2),
        .data_in(out_fifo_data_in2),
        .valid_out(out_fifo_valid_out2),
        .ready_out(out_fifo_ready_out2),
        .data_out(out_fifo_data_out2)
    );

    initial begin
        clk = 0;
        rst = 0;
        #6
        rst = 1;
        @(posedge clk);
        @(posedge clk);
        for (integer i = 0; i < 64; i = i + 1) begin
            in_fifo_valid_in0 = 1;
            in_fifo_data_in0 = 16 + i;
            out_fifo_ready_in0 = 1;

            in_fifo_valid_in1 = 1;
            in_fifo_data_in1 = 16 + i;
            out_fifo_ready_in1 = 1;

            in_fifo_valid_in2 = 1;
            in_fifo_data_in2 = 16 + i;
            out_fifo_ready_in2 = 1;
            @(posedge clk);
        end
        in_fifo_valid_in0 = 0;
        in_fifo_valid_in1 = 0;
        in_fifo_valid_in2 = 0;
        #2000
        $finish;
    end

    always #5 clk = ~clk;

    initial begin
        $fsdbDumpfile("testbench.fsdb");
        $fsdbDumpMDA(0, testbench);
        $fsdbDumpvars(0, testbench);
        
        $vcdpluson;
        $vcdplusmemon;
        $vcdplusfile("testbench.vpd");
        
        $dumpon;
        $dumpfile("testbench.vpd");
        $dumpvars(0, testbench);
        $dumpoff;
        $display("dump success");
    end

endmodule

module my_fifo #(
    parameter DEPTH = 4
) (
    input clk,
    input rst,
    input valid_in,
    input ready_in,
    input [15:0] data_in,

    output wire valid_out,
    output wire ready_out,
    output reg [15:0] data_out
);

    reg [15:0] mems [DEPTH-1: 0];
    reg [$clog2(DEPTH): 0] pointer;
    wire state, push, pop;
    wire [$clog2(DEPTH) - 1: 0] addr;

    assign addr = pointer[$clog2(DEPTH) - 1: 0];
    assign state = pointer[$clog2(DEPTH)];
    assign push = ~state & valid_in;
    assign pop = state & ready_in;
    assign valid_out = state;
    assign ready_out = ~state;

    always @ (posedge clk, negedge rst) begin
        if (!rst) begin
            for (integer i = 0; i < DEPTH; i = i + 1) begin
                mems[i] <= 0;
            end
            
        end
        else begin
            if (push) mems[addr] <= data_in;
        end
    end

    always @ (*) begin
        if (pop) data_out <= mems[addr];
        else data_out <= 0;
    end

    always @ (posedge clk, negedge rst) begin
        if (!rst) pointer <= 0;
        else begin
            if (push | pop)    pointer <= pointer + 1;
        end
    end
    
endmodule
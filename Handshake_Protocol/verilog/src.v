module reg_valid_pip_unit (
    input clk,
    input rst,
    input valid_up,
    input [15:0] data_up,
    input ready_down,
    output wire valid_down,
    output wire [15:0] data_down,
    output wire ready_up
);

    reg valid_reg;
    reg [15:0] data_reg;
    wire push, pop;

    assign ready_up = !valid_reg | ready_down;
    assign valid_down = valid_reg;
    assign data_down = data_reg;

    assign push = valid_up & ready_up;
    assign pop = valid_reg & ready_down;

    always @ (posedge clk, negedge rst) begin
        if (!rst) begin
            data_reg <= 0;
            valid_reg <= 0;
        end
        else begin
            if (pop) begin
                data_reg <= 0;
                valid_reg <= 0;
            end
            if (push) begin
                data_reg <= data_up;
                valid_reg <= valid_up;
            end
        end
    end

endmodule

module reg_ready_pip_unit (
    input clk,
    input rst,
    input valid_up,
    input [15:0] data_up,
    input ready_down,
    output wire valid_down,
    output reg [15:0] data_down,
    output wire ready_up
);

    reg ready_reg;
    reg [15:0] data_reg;
    wire push, pop;

    assign ready_up = ready_reg;

    // assign data_down = ready_reg ? data_up : data_reg;
    assign valid_down = valid_up | ~ready_reg;
    assign push = valid_up & ready_up;
    assign pop = valid_down & ready_down;

    always @ (posedge clk, negedge rst) begin
        if (!rst) begin
            data_reg <= 0;
            ready_reg <= 1;
        end
        else begin
            if(push) begin
                data_reg <= data_up;
                ready_reg <= ready_down;
            end
            if(pop) begin
                data_reg <= 0;
                ready_reg <= 1;
            end
        end
    end

    always @ (*) begin
        data_down = 0;
        if (push) begin
            data_down = data_reg;
        end
        if (pop) begin
            data_down = data_up;
        end
    end
endmodule

module reg_both_pip_unit (
    input clk,
    input rst,
    input valid_up,
    input [15:0] data_up,
    input ready_down,
    output wire valid_down,
    output wire [15:0] data_down,
    output wire ready_up
);

    wire [15:0] mid_data;
    wire mid_valid, mid_ready;

    reg_ready_pip_unit U0 (
        .clk(clk),
        .rst(rst),
        .valid_up(valid_up),
        .data_up(data_up),
        .ready_down(mid_ready),
        .valid_down(mid_valid),
        .data_down(mid_data),
        .ready_up(ready_up)
    );

    reg_valid_pip_unit U1 (
        .clk(clk),
        .rst(rst),
        .valid_up(mid_valid),
        .data_up(mid_data),
        .ready_down(ready_down),
        .valid_down(valid_down),
        .data_down(data_down),
        .ready_up(mid_ready)
    );

endmodule

module reg_both_pip_unit_my (
    input clk,
    input rst,
    input valid_up,
    input [15:0] data_up,
    input ready_down,
    output reg valid_down,
    output reg [15:0] data_down,
    output wire ready_up
);

    reg valid_reg, ready_reg;
    reg [15:0] data_reg;
    reg [15:0] buf_reg;
    wire push, pop;

    assign valid_down = valid_reg;
    assign ready_up = ready_reg;

    assign push = valid_up & ready_reg;
    assign pop = valid_reg & ready_down;

    assign data_down = (ready_down & ~ready_up) ? buf_reg : data_reg;

    always @ (posedge clk, negedge rst) begin
        if (!rst) begin
            valid_reg <= 0;
            ready_reg <= 1;
        end
        else begin
            if (push) valid_reg <= 1;
            ready_reg <= ready_down;
        end
    end

    always @ (posedge clk, negedge rst) begin
        if (!rst) begin
            data_reg <= 0;
            buf_reg <= 0;
        end
        else begin
            if (push) data_reg <= data_up;
            if (push & !ready_down) buf_reg <= data_reg;
        end
    end

endmodule

module reg_valid_pip #(
    parameter DEPTH = 6
) (
    input clk,
    input rst,
    input master_valid_in,
    input [15:0] master_data_in,
    input slave_ready_in,
    output wire master_valid_out,
    output wire [15:0] master_data_out,
    output wire slave_ready_out
);

    wire [DEPTH:0] valids, readys;
    wire [15:0] data [DEPTH: 0];

    assign valids[0] = master_valid_in;
    assign readys[DEPTH] = slave_ready_in;
    assign master_valid_out = valids[DEPTH];
    assign slave_ready_out = readys[0];
    assign data[0] = master_data_in;
    assign master_data_out = data[DEPTH];

    genvar i;

    generate
        for (i = 1; i < DEPTH+1; i = i + 1) begin
            reg_valid_pip_unit reg_valid_inst(
                .clk(clk),
                .rst(rst),
                .valid_up(valids[i-1]),
                .data_up(data[i-1]),
                .ready_down(readys[DEPTH+1-i]),
                .valid_down(valids[i]),
                .data_down(data[i]),
                .ready_up(readys[DEPTH-i])
            );
        end
    endgenerate

endmodule

module reg_ready_pip #(
    parameter DEPTH = 6
) (
    input clk,
    input rst,
    input master_valid_in,
    input [15:0] master_data_in,
    input slave_ready_in,
    output wire master_valid_out,
    output wire [15:0] master_data_out,
    output wire slave_ready_out
);

    wire [DEPTH:0] valids, readys;
    wire [15:0] data [DEPTH: 0];

    assign valids[0] = master_valid_in;
    assign readys[DEPTH] = slave_ready_in;
    assign master_valid_out = valids[DEPTH];
    assign slave_ready_out = readys[0];
    assign data[0] = master_data_in;
    assign master_data_out = data[DEPTH];

    genvar i;

    generate
        for (i = 1; i < DEPTH+1; i = i + 1) begin
            reg_ready_pip_unit reg_ready_inst(
                .clk(clk),
                .rst(rst),
                .valid_up(valids[i-1]),
                .data_up(data[i-1]),
                .ready_down(readys[i]),
                .valid_down(valids[i]),
                .data_down(data[i]),
                .ready_up(readys[i-1])
            );
        end
    endgenerate

endmodule

module reg_both_pip #(
    parameter DEPTH = 6
) (
    input clk,
    input rst,
    input master_valid_in,
    input [15:0] master_data_in,
    input slave_ready_in,
    output wire master_valid_out,
    output wire [15:0] master_data_out,
    output wire slave_ready_out
);

    wire [DEPTH:0] valids, readys;
    wire [15:0] data [DEPTH: 0];

    assign valids[0] = master_valid_in;
    assign readys[DEPTH] = slave_ready_in;
    assign master_valid_out = valids[DEPTH];
    assign slave_ready_out = readys[0];
    assign data[0] = master_data_in;
    assign master_data_out = data[DEPTH];

    genvar i;

    generate
        for (i = 1; i < DEPTH+1; i = i + 1) begin
            reg_both_pip_unit reg_both_inst(
                .clk(clk),
                .rst(rst),
                .valid_up(valids[i-1]),
                .data_up(data[i-1]),
                .ready_down(readys[i]),
                .valid_down(valids[i]),
                .data_down(data[i]),
                .ready_up(readys[i-1])
            );
        end
    endgenerate

endmodule
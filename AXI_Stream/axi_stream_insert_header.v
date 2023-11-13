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
// Your code here

    /*  Registers   */
    reg [DATA_WD-1 : 0] data_reg;
    reg [DATA_WD-1 : 0] data_out_reg;
    reg [DATA_WD-1 : 0] data_out_skid_reg;

    reg [DATA_BYTE_WD-1 : 0] keep_insert_reg;
    reg [DATA_BYTE_WD-1 : 0] keep_in_reg;
    reg [DATA_BYTE_WD-1 : 0] keep_out_reg;
    reg [DATA_BYTE_WD-1 : 0] keep_out_skid_reg;

    reg last_reg;
    reg last_out_reg;
    reg last_out_skid_reg;

    reg valid_out_reg;
    reg valid_out_skid_reg;
    reg valid_insert_reg;

    reg ready_reg;
    reg ready_insert_reg;

    reg working;

    /*  Wires   */
    wire push;
    wire data_push;
    wire data_pop;
    wire header_push;
    wire last_push;

    wire skid_push;
    wire skid_out_en;

    wire overflow;

    /*  Outputs */
    assign skid_out_en = ready_in && ~ready_out;

    assign data_out = skid_out_en ? data_out_skid_reg : data_out_reg;
    assign keep_out = skid_out_en ? (last_out ? keep_out_skid_reg : 4'b1111) : (last_out ? keep_out_reg : 4'b1111);
    assign last_out = skid_out_en ? last_out_skid_reg : last_out_reg;
    assign valid_out = skid_out_en ? valid_out_skid_reg : valid_out_reg;
    
    assign ready_in = ready_reg;
    assign ready_insert = ~working;

    /*  Inside  */
    assign data_pop = valid_out && ready_out;

    assign header_push = valid_insert && ready_insert;
    assign last_push = last_in && push;

    /*  Start Stream Transfer   */
    always @(posedge clk, negedge rst_n) begin
        if (!rst_n) begin
            working <= 0;
        end
        else begin
            if (header_push && push) begin
                working <= 1;
            end
            else if (last_out_reg) begin
                working <= 0;
            end
        end
    end

    /*  Join Module */
    reg [DATA_WD-1 : 0] shift_left_in;
    reg [DATA_WD-1 : 0] shift_left_out;
    reg [DATA_WD-1 : 0] shift_right_in;
    reg [DATA_WD-1 : 0] shift_right_out;

    wire [DATA_BYTE_WD-1 : 0] shift_sel;

    assign shift_sel = working ? keep_insert_reg : keep_insert;

    always @(*) begin
        shift_left_out = shift_word_left(shift_left_in, shift_sel);
    end

    always @(*) begin
        shift_right_out = shift_word_right(shift_right_in, shift_sel);
    end

    reg [DATA_WD-1 : 0]data_valid;
    always @(*) begin
        data_valid = valid_word(data_in, keep_in);
    end

    always @(*) begin
        if (~working) begin
            shift_left_in = header_insert;
        end
        else begin
            shift_left_in = data_reg;
        end
    end

    always @(*) begin
        if (last_reg) begin
            shift_right_in = 0;
        end
        else begin
            shift_right_in = data_valid;
        end
    end

    /*  Join Left and Right */
    always @(posedge clk, negedge rst_n) begin
        if (!rst_n) begin
            data_out_reg <= 0;
            keep_insert_reg <= 0;
        end
        else begin
            if ((header_push && push) || data_push || (last_reg && working)) begin
                data_out_reg <= shift_left_out | shift_right_out;
                keep_insert_reg <= keep_insert;
            end else if (last_out_reg) begin
                data_out_reg <= 0;
            end
        end
    end

    /*  Data Buffer */
    assign push = valid_in && ready_in;
    assign data_push = push && working;

    always @(posedge clk, negedge rst_n) begin
        if (!rst_n) begin
            data_reg <= 0;
            keep_in_reg <= 0;
            keep_out_reg <= 0;
            last_reg <= 0;
        end
        else begin
            if (last_out) begin
                last_reg <= 0;
                data_reg <= 0;
                keep_in_reg <= 0;
                keep_out_reg <= 0;
            end
            else if (push) begin
                data_reg <= data_valid;
                last_reg <= last_in;
                keep_in_reg <= keep_in;
                if (last_in) begin
                    if (overflow) begin
                        keep_out_reg <= shift_keep_overflow(keep_in, keep_insert);
                    end
                    else begin
                        keep_out_reg <= shift_keep(keep_in, keep_insert);
                    end
                end
                else begin
                    keep_out_reg <= keep_in;
                end
            end
            else if (last_out_reg) begin
                data_reg <= 0;
                keep_out_reg <= 0;
                last_reg <= 0;
                keep_in_reg <= 0;
            end
        end
    end

    /*  Generate valid_out & ready_out  */
    always @(posedge clk, negedge rst_n) begin
        if (!rst_n) begin
            valid_out_reg <= 0;
        end
        else begin
            if (last_out) begin
                valid_out_reg <= 0;
            end
            else if (data_push || (!working && header_push && push) || (last_reg && working)) begin
                valid_out_reg <= 1;
            end
            else if ((data_pop && ready_in)) begin
                valid_out_reg <= 0;
            end
        end
    end

    always @(posedge clk, negedge rst_n) begin
        if (!rst_n) begin
            ready_reg <= 1;
        end
        else begin
            ready_reg <= ready_out;
        end
    end

    /*  Generate Last   */
    assign overflow = (shift_sel & keep_in) != 0;
    always @(posedge clk, negedge rst_n) begin
        if (!rst_n) begin
            last_out_reg <= 0;
        end
        else begin
            if (last_out && data_pop) begin
                last_out_reg <= 0;
            end
            else if (overflow) begin
                last_out_reg <= last_reg;
            end
            else begin
                last_out_reg <= last_in;
            end
        end
    end


    /*  SKID buffer */
    assign skid_push = data_push && ~ready_out;

    always @(posedge clk, negedge rst_n) begin
        if (!rst_n) begin
            data_out_skid_reg <= 0;
            keep_out_skid_reg <= 0;
            last_out_skid_reg <= 0;
            valid_out_skid_reg <= 0;
        end
        else begin
            if (skid_push) begin
                data_out_skid_reg <= data_out_reg;
                keep_out_skid_reg <= keep_out_reg;
                last_out_skid_reg <= last_out_reg;
                valid_out_skid_reg <= valid_out_reg;
            end
        end
    end

    function [DATA_WD-1 : 0] valid_word;
        input [DATA_WD-1 : 0] d_in;
        input [DATA_BYTE_WD-1 : 0] keep;
        integer i, j;
        for(i = 0; i < DATA_BYTE_WD; i = i + 1) begin
            for (j = 0; j < 8; j = j + 1) begin
                valid_word[i*8+j] = d_in[i*8+j] & keep[i];
            end
        end
    endfunction

    function [DATA_BYTE_WD-1 : 0] shift_keep_overflow;
        input [DATA_BYTE_WD-1 : 0] keep_in;
        input [DATA_BYTE_WD-1 : 0] len;
        case (len)
        4'b1111: shift_keep_overflow = keep_in;
        4'b0111: shift_keep_overflow = keep_in << 1;
        4'b0011: shift_keep_overflow = keep_in << 2;
        4'b0001: shift_keep_overflow = keep_in << 3;
        default: shift_keep_overflow = 0;
        endcase
    endfunction

    function [DATA_BYTE_WD-1 : 0] shift_keep;
        input [DATA_BYTE_WD-1 : 0] keep_in;
        input [DATA_BYTE_WD-1 : 0] len;
        case (len)
        4'b0111: shift_keep = 4'b1111;
        4'b0011: shift_keep = ($signed(keep_in)) >>> 2;
        4'b0001: shift_keep = ($signed(keep_in)) >>> 1;
        default: shift_keep = 0;
        endcase
    endfunction

    function [DATA_WD-1 : 0] shift_word_left;
        input [DATA_WD-1 : 0] d_in;
        input [DATA_BYTE_WD-1 : 0] len;
        case (len)
        4'b1111: shift_word_left = d_in;
        4'b0111: shift_word_left = d_in << 8;
        4'b0011: shift_word_left = d_in << 16;
        4'b0001: shift_word_left = d_in << 24;
        default: shift_word_left = 0;
        endcase
    endfunction

    function [DATA_WD-1 : 0] shift_word_right;
        input [DATA_WD-1 : 0] d_in;
        input [DATA_BYTE_WD-1 : 0] len;
        case (len)
        4'b1111: shift_word_right = 0;
        4'b0111: shift_word_right = d_in >> 24;
        4'b0011: shift_word_right = d_in >> 16;
        4'b0001: shift_word_right = d_in >> 8;
        default: shift_word_right = d_in;
        endcase
    endfunction

endmodule
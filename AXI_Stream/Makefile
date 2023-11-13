SIM ?= verilator
TOPLEVEL_LANG ?= verilog

VERILOG_SOURCES += $(PWD)/axi_stream_insert_header.v

TOPLEVEL = axi_stream_insert_header

MODULE = test_axi_stream_model

EXTRA_ARGS += --trace --trace-structs

include $(shell cocotb-config --makefiles)/Makefile.sim
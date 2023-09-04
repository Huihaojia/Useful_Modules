all: clean com sim verdi

com:
	vcs \
	-f filelist.f \
	-full64 -R +vc +v2k -sverilog -debug_all \
	-timescale=1ns/10ps \
	-l com.log \
	-o testbench.simv \
	-fsdb +define+FSDB \
	| tee vcs.log

sim:
	./testbench.simv -l sim.log

clean:
	rm -rf *.log simv *.daidir csrc *.key DVEfiles *.vpd *.fsdb *.simv

verdi:
	verdi \
	-nologo \
	-f filelist.f \
	-ssf *.fsdb &
debImport "-f" "filelist.f"
debLoadSimResult /home/hhj/codes/MIT_Lab/Tutorials/ExLab01/testbench.fsdb
wvCreateWindow
srcHBSelect "testbench" -win $_nTrace1
srcSetScope -win $_nTrace1 "testbench" -delim "."
srcHBSelect "testbench" -win $_nTrace1
srcHBSelect "testbench.U0" -win $_nTrace1
srcSetScope -win $_nTrace1 "testbench.U0" -delim "."
srcHBSelect "testbench.U0" -win $_nTrace1
srcHBSelect "testbench.U0.genblk1\[1\]" -win $_nTrace1
srcSetScope -win $_nTrace1 "testbench.U0.genblk1\[1\]" -delim "."
srcHBSelect "testbench.U0.genblk1\[1\]" -win $_nTrace1
srcHBSelect "testbench.U0.genblk1\[2\]" -win $_nTrace1
srcSetScope -win $_nTrace1 "testbench.U0.genblk1\[2\]" -delim "."
srcHBDrag -win $_nTrace1
srcHBSelect "testbench.U0.genblk1\[3\]" -win $_nTrace1
srcSetScope -win $_nTrace1 "testbench.U0.genblk1\[3\]" -delim "."
srcHBSelect "testbench.U0.genblk1\[3\]" -win $_nTrace1
srcHBSelect "testbench.U0.genblk1\[4\]" -win $_nTrace1
srcSetScope -win $_nTrace1 "testbench.U0.genblk1\[4\]" -delim "."
srcHBSelect "testbench.U0.genblk1\[4\]" -win $_nTrace1
srcHBSelect "testbench.U0.genblk1\[1\].reg_both_inst" -win $_nTrace1
srcSetScope -win $_nTrace1 "testbench.U0.genblk1\[1\].reg_both_inst" -delim "."
srcHBSelect "testbench.U0.genblk1\[1\].reg_both_inst" -win $_nTrace1
srcDeselectAll -win $_nTrace1
srcSelect -signal "data_down" -line 99 -pos 1 -win $_nTrace1
srcAddSelectedToWave -clipboard -win $_nTrace1
wvDrop -win $_nWave2
srcHBSelect "testbench.U0.genblk1\[2\]" -win $_nTrace1
srcSetScope -win $_nTrace1 "testbench.U0.genblk1\[2\]" -delim "."
srcHBSelect "testbench.U0.genblk1\[2\]" -win $_nTrace1
srcHBSelect "testbench.U0.genblk1\[2\].reg_both_inst" -win $_nTrace1
srcSetScope -win $_nTrace1 "testbench.U0.genblk1\[2\].reg_both_inst" -delim "."
srcHBSelect "testbench.U0.genblk1\[2\].reg_both_inst" -win $_nTrace1
srcDeselectAll -win $_nTrace1
srcSelect -signal "data_down" -line 99 -pos 1 -win $_nTrace1
srcAddSelectedToWave -clipboard -win $_nTrace1
wvDrop -win $_nWave2
srcHBSelect "testbench.U0.genblk1\[3\]" -win $_nTrace1
srcSetScope -win $_nTrace1 "testbench.U0.genblk1\[3\]" -delim "."
srcHBSelect "testbench.U0.genblk1\[3\]" -win $_nTrace1
srcHBSelect "testbench.U0.genblk1\[3\].reg_both_inst" -win $_nTrace1
srcSetScope -win $_nTrace1 "testbench.U0.genblk1\[3\].reg_both_inst" -delim "."
srcHBSelect "testbench.U0.genblk1\[3\].reg_both_inst" -win $_nTrace1
srcSelect -signal "data_down" -line 99 -pos 1 -win $_nTrace1
srcAddSelectedToWave -clipboard -win $_nTrace1
wvDrop -win $_nWave2
srcHBSelect "testbench.U0.genblk1\[4\]" -win $_nTrace1
srcSetScope -win $_nTrace1 "testbench.U0.genblk1\[4\]" -delim "."
srcHBSelect "testbench.U0.genblk1\[4\]" -win $_nTrace1
srcHBSelect "testbench.U0.genblk1\[4\].reg_both_inst" -win $_nTrace1
srcSetScope -win $_nTrace1 "testbench.U0.genblk1\[4\].reg_both_inst" -delim "."
srcHBSelect "testbench.U0.genblk1\[4\].reg_both_inst" -win $_nTrace1
srcDeselectAll -win $_nTrace1
srcDeselectAll -win $_nTrace1
srcSelect -signal "data_down" -line 99 -pos 1 -win $_nTrace1
srcAddSelectedToWave -clipboard -win $_nTrace1
wvDrop -win $_nWave2
wvSetCursor -win $_nWave2 13922.955992 -snap {("G1" 4)}
wvZoomAll -win $_nWave2
wvZoom -win $_nWave2 53486.748477 119274.537915
debExit
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        wvZoom -win $_nWave2 59500.590724 82553.652674
debExit

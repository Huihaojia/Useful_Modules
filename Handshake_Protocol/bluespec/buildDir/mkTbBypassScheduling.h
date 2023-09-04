/*
 * Generated by Bluespec Compiler (build 14ff62d)
 * 
 * On Wed Jun 28 21:40:06 CST 2023
 * 
 */

/* Generation options: keep-fires */
#ifndef __mkTbBypassScheduling_h__
#define __mkTbBypassScheduling_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkTbBypassScheduling module */
class MOD_mkTbBypassScheduling : public Module {
 
 /* Clock handles */
 private:
  tClock __clk_handle_0;
 
 /* Clock gate handles */
 public:
  tUInt8 *clk_gate[0];
 
 /* Instantiation parameters */
 public:
 
 /* Module state */
 public:
  MOD_Reg<tUInt32> INST_m_cycle;
  MOD_Reg<tUInt8> INST_m_fifo_1_deqPtr_ehrReg;
  MOD_Wire<tUInt8> INST_m_fifo_1_deqPtr_ignored_wires_0;
  MOD_Wire<tUInt8> INST_m_fifo_1_deqPtr_ignored_wires_1;
  MOD_Wire<tUInt8> INST_m_fifo_1_deqPtr_ignored_wires_2;
  MOD_Reg<tUInt8> INST_m_fifo_1_deqPtr_virtual_reg_0;
  MOD_Reg<tUInt8> INST_m_fifo_1_deqPtr_virtual_reg_1;
  MOD_Reg<tUInt8> INST_m_fifo_1_deqPtr_virtual_reg_2;
  MOD_Wire<tUInt8> INST_m_fifo_1_deqPtr_wires_0;
  MOD_Wire<tUInt8> INST_m_fifo_1_deqPtr_wires_1;
  MOD_Wire<tUInt8> INST_m_fifo_1_deqPtr_wires_2;
  MOD_Reg<tUInt8> INST_m_fifo_1_ehr_ehrReg;
  MOD_Wire<tUInt8> INST_m_fifo_1_ehr_ignored_wires_0;
  MOD_Wire<tUInt8> INST_m_fifo_1_ehr_ignored_wires_1;
  MOD_Wire<tUInt8> INST_m_fifo_1_ehr_ignored_wires_2;
  MOD_Reg<tUInt8> INST_m_fifo_1_ehr_virtual_reg_0;
  MOD_Reg<tUInt8> INST_m_fifo_1_ehr_virtual_reg_1;
  MOD_Reg<tUInt8> INST_m_fifo_1_ehr_virtual_reg_2;
  MOD_Wire<tUInt8> INST_m_fifo_1_ehr_wires_0;
  MOD_Wire<tUInt8> INST_m_fifo_1_ehr_wires_1;
  MOD_Wire<tUInt8> INST_m_fifo_1_ehr_wires_2;
  MOD_Reg<tUInt8> INST_m_fifo_1_enqPtr_ehrReg;
  MOD_Wire<tUInt8> INST_m_fifo_1_enqPtr_ignored_wires_0;
  MOD_Wire<tUInt8> INST_m_fifo_1_enqPtr_ignored_wires_1;
  MOD_Wire<tUInt8> INST_m_fifo_1_enqPtr_ignored_wires_2;
  MOD_Reg<tUInt8> INST_m_fifo_1_enqPtr_virtual_reg_0;
  MOD_Reg<tUInt8> INST_m_fifo_1_enqPtr_virtual_reg_1;
  MOD_Reg<tUInt8> INST_m_fifo_1_enqPtr_virtual_reg_2;
  MOD_Wire<tUInt8> INST_m_fifo_1_enqPtr_wires_0;
  MOD_Wire<tUInt8> INST_m_fifo_1_enqPtr_wires_1;
  MOD_Wire<tUInt8> INST_m_fifo_1_enqPtr_wires_2;
  MOD_Reg<tUInt8> INST_m_fifo_1_nEmpty_ehrReg;
  MOD_Wire<tUInt8> INST_m_fifo_1_nEmpty_ignored_wires_0;
  MOD_Wire<tUInt8> INST_m_fifo_1_nEmpty_ignored_wires_1;
  MOD_Wire<tUInt8> INST_m_fifo_1_nEmpty_ignored_wires_2;
  MOD_Reg<tUInt8> INST_m_fifo_1_nEmpty_virtual_reg_0;
  MOD_Reg<tUInt8> INST_m_fifo_1_nEmpty_virtual_reg_1;
  MOD_Reg<tUInt8> INST_m_fifo_1_nEmpty_virtual_reg_2;
  MOD_Wire<tUInt8> INST_m_fifo_1_nEmpty_wires_0;
  MOD_Wire<tUInt8> INST_m_fifo_1_nEmpty_wires_1;
  MOD_Wire<tUInt8> INST_m_fifo_1_nEmpty_wires_2;
  MOD_Reg<tUInt8> INST_m_fifo_1_nFull_ehrReg;
  MOD_Wire<tUInt8> INST_m_fifo_1_nFull_ignored_wires_0;
  MOD_Wire<tUInt8> INST_m_fifo_1_nFull_ignored_wires_1;
  MOD_Wire<tUInt8> INST_m_fifo_1_nFull_ignored_wires_2;
  MOD_Reg<tUInt8> INST_m_fifo_1_nFull_virtual_reg_0;
  MOD_Reg<tUInt8> INST_m_fifo_1_nFull_virtual_reg_1;
  MOD_Reg<tUInt8> INST_m_fifo_1_nFull_virtual_reg_2;
  MOD_Wire<tUInt8> INST_m_fifo_1_nFull_wires_0;
  MOD_Wire<tUInt8> INST_m_fifo_1_nFull_wires_1;
  MOD_Wire<tUInt8> INST_m_fifo_1_nFull_wires_2;
  MOD_Reg<tUInt8> INST_m_fifo_1_regs_0;
  MOD_Reg<tUInt8> INST_m_fifo_1_regs_1;
  MOD_Reg<tUInt8> INST_m_fifo_1_regs_2;
  MOD_Reg<tUInt8> INST_m_fifo_2_deqPtr_ehrReg;
  MOD_Wire<tUInt8> INST_m_fifo_2_deqPtr_ignored_wires_0;
  MOD_Wire<tUInt8> INST_m_fifo_2_deqPtr_ignored_wires_1;
  MOD_Wire<tUInt8> INST_m_fifo_2_deqPtr_ignored_wires_2;
  MOD_Reg<tUInt8> INST_m_fifo_2_deqPtr_virtual_reg_0;
  MOD_Reg<tUInt8> INST_m_fifo_2_deqPtr_virtual_reg_1;
  MOD_Reg<tUInt8> INST_m_fifo_2_deqPtr_virtual_reg_2;
  MOD_Wire<tUInt8> INST_m_fifo_2_deqPtr_wires_0;
  MOD_Wire<tUInt8> INST_m_fifo_2_deqPtr_wires_1;
  MOD_Wire<tUInt8> INST_m_fifo_2_deqPtr_wires_2;
  MOD_Reg<tUInt8> INST_m_fifo_2_ehr_ehrReg;
  MOD_Wire<tUInt8> INST_m_fifo_2_ehr_ignored_wires_0;
  MOD_Wire<tUInt8> INST_m_fifo_2_ehr_ignored_wires_1;
  MOD_Wire<tUInt8> INST_m_fifo_2_ehr_ignored_wires_2;
  MOD_Reg<tUInt8> INST_m_fifo_2_ehr_virtual_reg_0;
  MOD_Reg<tUInt8> INST_m_fifo_2_ehr_virtual_reg_1;
  MOD_Reg<tUInt8> INST_m_fifo_2_ehr_virtual_reg_2;
  MOD_Wire<tUInt8> INST_m_fifo_2_ehr_wires_0;
  MOD_Wire<tUInt8> INST_m_fifo_2_ehr_wires_1;
  MOD_Wire<tUInt8> INST_m_fifo_2_ehr_wires_2;
  MOD_Reg<tUInt8> INST_m_fifo_2_enqPtr_ehrReg;
  MOD_Wire<tUInt8> INST_m_fifo_2_enqPtr_ignored_wires_0;
  MOD_Wire<tUInt8> INST_m_fifo_2_enqPtr_ignored_wires_1;
  MOD_Wire<tUInt8> INST_m_fifo_2_enqPtr_ignored_wires_2;
  MOD_Reg<tUInt8> INST_m_fifo_2_enqPtr_virtual_reg_0;
  MOD_Reg<tUInt8> INST_m_fifo_2_enqPtr_virtual_reg_1;
  MOD_Reg<tUInt8> INST_m_fifo_2_enqPtr_virtual_reg_2;
  MOD_Wire<tUInt8> INST_m_fifo_2_enqPtr_wires_0;
  MOD_Wire<tUInt8> INST_m_fifo_2_enqPtr_wires_1;
  MOD_Wire<tUInt8> INST_m_fifo_2_enqPtr_wires_2;
  MOD_Reg<tUInt8> INST_m_fifo_2_nEmpty_ehrReg;
  MOD_Wire<tUInt8> INST_m_fifo_2_nEmpty_ignored_wires_0;
  MOD_Wire<tUInt8> INST_m_fifo_2_nEmpty_ignored_wires_1;
  MOD_Wire<tUInt8> INST_m_fifo_2_nEmpty_ignored_wires_2;
  MOD_Reg<tUInt8> INST_m_fifo_2_nEmpty_virtual_reg_0;
  MOD_Reg<tUInt8> INST_m_fifo_2_nEmpty_virtual_reg_1;
  MOD_Reg<tUInt8> INST_m_fifo_2_nEmpty_virtual_reg_2;
  MOD_Wire<tUInt8> INST_m_fifo_2_nEmpty_wires_0;
  MOD_Wire<tUInt8> INST_m_fifo_2_nEmpty_wires_1;
  MOD_Wire<tUInt8> INST_m_fifo_2_nEmpty_wires_2;
  MOD_Reg<tUInt8> INST_m_fifo_2_nFull_ehrReg;
  MOD_Wire<tUInt8> INST_m_fifo_2_nFull_ignored_wires_0;
  MOD_Wire<tUInt8> INST_m_fifo_2_nFull_ignored_wires_1;
  MOD_Wire<tUInt8> INST_m_fifo_2_nFull_ignored_wires_2;
  MOD_Reg<tUInt8> INST_m_fifo_2_nFull_virtual_reg_0;
  MOD_Reg<tUInt8> INST_m_fifo_2_nFull_virtual_reg_1;
  MOD_Reg<tUInt8> INST_m_fifo_2_nFull_virtual_reg_2;
  MOD_Wire<tUInt8> INST_m_fifo_2_nFull_wires_0;
  MOD_Wire<tUInt8> INST_m_fifo_2_nFull_wires_1;
  MOD_Wire<tUInt8> INST_m_fifo_2_nFull_wires_2;
  MOD_Reg<tUInt8> INST_m_fifo_2_regs_0;
  MOD_Reg<tUInt8> INST_m_fifo_2_regs_1;
  MOD_Reg<tUInt8> INST_m_fifo_2_regs_2;
 
 /* Constructor */
 public:
  MOD_mkTbBypassScheduling(tSimStateHdl simHdl, char const *name, Module *parent);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
 
 /* Publicly accessible definitions */
 public:
  tUInt8 DEF_WILL_FIRE_RL_m_cycle_stuff;
  tUInt8 DEF_CAN_FIRE_RL_m_cycle_stuff;
  tUInt8 DEF_WILL_FIRE_RL_m_clear_fifo_1;
  tUInt8 DEF_CAN_FIRE_RL_m_clear_fifo_1;
  tUInt8 DEF_WILL_FIRE_RL_m_deq_fifo_1;
  tUInt8 DEF_CAN_FIRE_RL_m_deq_fifo_1;
  tUInt8 DEF_WILL_FIRE_RL_m_enq_fifo_1;
  tUInt8 DEF_CAN_FIRE_RL_m_enq_fifo_1;
  tUInt8 DEF_WILL_FIRE_RL_m_fifo_2_ehr_canonicalize;
  tUInt8 DEF_CAN_FIRE_RL_m_fifo_2_ehr_canonicalize;
  tUInt8 DEF_WILL_FIRE_RL_m_fifo_1_ehr_canonicalize;
  tUInt8 DEF_CAN_FIRE_RL_m_fifo_1_ehr_canonicalize;
  tUInt8 DEF_WILL_FIRE_RL_m_fifo_2_nFull_canonicalize;
  tUInt8 DEF_CAN_FIRE_RL_m_fifo_2_nFull_canonicalize;
  tUInt8 DEF_WILL_FIRE_RL_m_fifo_2_nEmpty_canonicalize;
  tUInt8 DEF_CAN_FIRE_RL_m_fifo_2_nEmpty_canonicalize;
  tUInt8 DEF_WILL_FIRE_RL_m_fifo_2_deqPtr_canonicalize;
  tUInt8 DEF_CAN_FIRE_RL_m_fifo_2_deqPtr_canonicalize;
  tUInt8 DEF_WILL_FIRE_RL_m_fifo_2_enqPtr_canonicalize;
  tUInt8 DEF_CAN_FIRE_RL_m_fifo_2_enqPtr_canonicalize;
  tUInt8 DEF_WILL_FIRE_RL_m_fifo_1_nFull_canonicalize;
  tUInt8 DEF_CAN_FIRE_RL_m_fifo_1_nFull_canonicalize;
  tUInt8 DEF_WILL_FIRE_RL_m_fifo_1_nEmpty_canonicalize;
  tUInt8 DEF_CAN_FIRE_RL_m_fifo_1_nEmpty_canonicalize;
  tUInt8 DEF_WILL_FIRE_RL_m_fifo_1_deqPtr_canonicalize;
  tUInt8 DEF_CAN_FIRE_RL_m_fifo_1_deqPtr_canonicalize;
  tUInt8 DEF_WILL_FIRE_RL_m_fifo_1_enqPtr_canonicalize;
  tUInt8 DEF_CAN_FIRE_RL_m_fifo_1_enqPtr_canonicalize;
  tUInt8 DEF_m_fifo_1_ehr_virtual_reg_2_read____d101;
  tUInt8 DEF_x__h14349;
  tUInt8 DEF_def__h16662;
  tUInt8 DEF_m_fifo_1_ehr_virtual_reg_1_read____d102;
  tUInt8 DEF_m_fifo_1_nEmpty_virtual_reg_2_read____d144;
  tUInt8 DEF_m_fifo_1_nEmpty_virtual_reg_1_read____d145;
  tUInt8 DEF_m_fifo_1_nEmpty_wires_0_whas____d25;
  tUInt8 DEF_m_fifo_1_nEmpty_wires_0_wget____d26;
  tUInt8 DEF_m_fifo_1_nEmpty_ehrReg__h3566;
  tUInt8 DEF_IF_m_fifo_1_ehr_wires_0_whas__5_THEN_m_fifo_1__ETC___d88;
  tUInt8 DEF_IF_m_fifo_1_nEmpty_wires_0_whas__5_THEN_m_fifo_ETC___d28;
  tUInt8 DEF_IF_m_fifo_1_ehr_virtual_reg_2_read__01_OR_m_fi_ETC___d142;
 
 /* Local definitions */
 private:
  tUInt8 DEF_def__h16129;
  tUInt8 DEF_def__h15953;
  tUInt8 DEF_m_fifo_1_nFull_ehrReg__h4689;
  tUInt8 DEF_m_fifo_1_deqPtr_virtual_reg_2_read____d132;
  tUInt8 DEF_m_fifo_1_deqPtr_virtual_reg_1_read____d133;
  tUInt8 DEF_IF_m_fifo_1_deqPtr_wires_0_whas__5_THEN_m_fifo_ETC___d18;
  tUInt8 DEF_n__read__h12837;
  tUInt8 DEF_IF_m_fifo_1_ehr_wires_1_whas__3_THEN_m_fifo_1__ETC___d89;
  tUInt8 DEF_x__h16082;
  tUInt8 DEF_x__h15906;
  tUInt8 DEF_def__h15940;
  tUInt8 DEF_IF_m_fifo_1_nFull_wires_1_whas__3_THEN_m_fifo__ETC___d39;
  tUInt8 DEF_IF_m_fifo_1_nFull_wires_0_whas__5_THEN_m_fifo__ETC___d38;
  tUInt8 DEF_IF_m_fifo_1_nEmpty_wires_1_whas__3_THEN_m_fifo_ETC___d29;
 
 /* Rules */
 public:
  void RL_m_fifo_1_enqPtr_canonicalize();
  void RL_m_fifo_1_deqPtr_canonicalize();
  void RL_m_fifo_1_nEmpty_canonicalize();
  void RL_m_fifo_1_nFull_canonicalize();
  void RL_m_fifo_2_enqPtr_canonicalize();
  void RL_m_fifo_2_deqPtr_canonicalize();
  void RL_m_fifo_2_nEmpty_canonicalize();
  void RL_m_fifo_2_nFull_canonicalize();
  void RL_m_fifo_1_ehr_canonicalize();
  void RL_m_fifo_2_ehr_canonicalize();
  void RL_m_enq_fifo_1();
  void RL_m_deq_fifo_1();
  void RL_m_clear_fifo_1();
  void RL_m_cycle_stuff();
 
 /* Methods */
 public:
 
 /* Reset routines */
 public:
  void reset_RST_N(tUInt8 ARG_rst_in);
 
 /* Static handles to reset routines */
 public:
 
 /* Pointers to reset fns in parent module for asserting output resets */
 private:
 
 /* Functions for the parent module to register its reset fns */
 public:
 
 /* Functions to set the elaborated clock id */
 public:
  void set_clk_0(char const *s);
 
 /* State dumping routine */
 public:
  void dump_state(unsigned int indent);
 
 /* VCD dumping routines */
 public:
  unsigned int dump_VCD_defs(unsigned int levels);
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTbBypassScheduling &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkTbBypassScheduling &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkTbBypassScheduling &backing);
};

#endif /* ifndef __mkTbBypassScheduling_h__ */

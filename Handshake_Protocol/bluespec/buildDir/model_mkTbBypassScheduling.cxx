/*
 * Generated by Bluespec Compiler (build 14ff62d)
 * 
 * On Wed Jun 28 21:40:06 CST 2023
 * 
 */
#include "bluesim_primitives.h"
#include "model_mkTbBypassScheduling.h"

#include <cstdlib>
#include <time.h>
#include "bluesim_kernel_api.h"
#include "bs_vcd.h"
#include "bs_reset.h"


/* Constructor */
MODEL_mkTbBypassScheduling::MODEL_mkTbBypassScheduling()
{
  mkTbBypassScheduling_instance = NULL;
}

/* Function for creating a new model */
void * new_MODEL_mkTbBypassScheduling()
{
  MODEL_mkTbBypassScheduling *model = new MODEL_mkTbBypassScheduling();
  return (void *)(model);
}

/* Schedule functions */

static void schedule_posedge_CLK(tSimStateHdl simHdl, void *instance_ptr)
       {
	 MOD_mkTbBypassScheduling &INST_top = *((MOD_mkTbBypassScheduling *)(instance_ptr));
	 INST_top.DEF_CAN_FIRE_RL_m_clear_fifo_1 = (tUInt8)1u;
	 INST_top.DEF_WILL_FIRE_RL_m_clear_fifo_1 = INST_top.DEF_CAN_FIRE_RL_m_clear_fifo_1;
	 INST_top.DEF_CAN_FIRE_RL_m_cycle_stuff = (tUInt8)1u;
	 INST_top.DEF_WILL_FIRE_RL_m_cycle_stuff = INST_top.DEF_CAN_FIRE_RL_m_cycle_stuff;
	 INST_top.DEF_CAN_FIRE_RL_m_enq_fifo_1 = (tUInt8)1u;
	 INST_top.DEF_WILL_FIRE_RL_m_enq_fifo_1 = INST_top.DEF_CAN_FIRE_RL_m_enq_fifo_1;
	 INST_top.DEF_CAN_FIRE_RL_m_fifo_1_deqPtr_canonicalize = (tUInt8)1u;
	 INST_top.DEF_WILL_FIRE_RL_m_fifo_1_deqPtr_canonicalize = INST_top.DEF_CAN_FIRE_RL_m_fifo_1_deqPtr_canonicalize;
	 INST_top.DEF_CAN_FIRE_RL_m_fifo_1_enqPtr_canonicalize = (tUInt8)1u;
	 INST_top.DEF_WILL_FIRE_RL_m_fifo_1_enqPtr_canonicalize = INST_top.DEF_CAN_FIRE_RL_m_fifo_1_enqPtr_canonicalize;
	 INST_top.DEF_CAN_FIRE_RL_m_fifo_1_ehr_canonicalize = (tUInt8)1u;
	 INST_top.DEF_WILL_FIRE_RL_m_fifo_1_ehr_canonicalize = INST_top.DEF_CAN_FIRE_RL_m_fifo_1_ehr_canonicalize;
	 INST_top.DEF_CAN_FIRE_RL_m_fifo_1_nEmpty_canonicalize = (tUInt8)1u;
	 INST_top.DEF_WILL_FIRE_RL_m_fifo_1_nEmpty_canonicalize = INST_top.DEF_CAN_FIRE_RL_m_fifo_1_nEmpty_canonicalize;
	 INST_top.DEF_CAN_FIRE_RL_m_fifo_1_nFull_canonicalize = (tUInt8)1u;
	 INST_top.DEF_WILL_FIRE_RL_m_fifo_1_nFull_canonicalize = INST_top.DEF_CAN_FIRE_RL_m_fifo_1_nFull_canonicalize;
	 INST_top.DEF_CAN_FIRE_RL_m_fifo_2_deqPtr_canonicalize = (tUInt8)1u;
	 INST_top.DEF_WILL_FIRE_RL_m_fifo_2_deqPtr_canonicalize = INST_top.DEF_CAN_FIRE_RL_m_fifo_2_deqPtr_canonicalize;
	 INST_top.DEF_CAN_FIRE_RL_m_fifo_2_ehr_canonicalize = (tUInt8)1u;
	 INST_top.DEF_WILL_FIRE_RL_m_fifo_2_ehr_canonicalize = INST_top.DEF_CAN_FIRE_RL_m_fifo_2_ehr_canonicalize;
	 INST_top.DEF_CAN_FIRE_RL_m_fifo_2_enqPtr_canonicalize = (tUInt8)1u;
	 INST_top.DEF_WILL_FIRE_RL_m_fifo_2_enqPtr_canonicalize = INST_top.DEF_CAN_FIRE_RL_m_fifo_2_enqPtr_canonicalize;
	 INST_top.DEF_CAN_FIRE_RL_m_fifo_2_nFull_canonicalize = (tUInt8)1u;
	 INST_top.DEF_WILL_FIRE_RL_m_fifo_2_nFull_canonicalize = INST_top.DEF_CAN_FIRE_RL_m_fifo_2_nFull_canonicalize;
	 INST_top.DEF_CAN_FIRE_RL_m_fifo_2_nEmpty_canonicalize = (tUInt8)1u;
	 INST_top.DEF_WILL_FIRE_RL_m_fifo_2_nEmpty_canonicalize = INST_top.DEF_CAN_FIRE_RL_m_fifo_2_nEmpty_canonicalize;
	 if (INST_top.DEF_WILL_FIRE_RL_m_enq_fifo_1)
	   INST_top.RL_m_enq_fifo_1();
	 INST_top.DEF_m_fifo_1_ehr_virtual_reg_2_read____d101 = INST_top.INST_m_fifo_1_ehr_virtual_reg_2.METH_read();
	 INST_top.DEF_def__h16662 = INST_top.INST_m_fifo_1_ehr_ehrReg.METH_read();
	 INST_top.DEF_m_fifo_1_ehr_virtual_reg_1_read____d102 = INST_top.INST_m_fifo_1_ehr_virtual_reg_1.METH_read();
	 INST_top.DEF_m_fifo_1_nEmpty_virtual_reg_2_read____d144 = INST_top.INST_m_fifo_1_nEmpty_virtual_reg_2.METH_read();
	 INST_top.DEF_m_fifo_1_nEmpty_virtual_reg_1_read____d145 = INST_top.INST_m_fifo_1_nEmpty_virtual_reg_1.METH_read();
	 INST_top.DEF_m_fifo_1_nEmpty_wires_0_whas____d25 = INST_top.INST_m_fifo_1_nEmpty_wires_0.METH_whas();
	 INST_top.DEF_m_fifo_1_nEmpty_wires_0_wget____d26 = INST_top.INST_m_fifo_1_nEmpty_wires_0.METH_wget();
	 INST_top.DEF_m_fifo_1_nEmpty_ehrReg__h3566 = INST_top.INST_m_fifo_1_nEmpty_ehrReg.METH_read();
	 INST_top.DEF_IF_m_fifo_1_ehr_wires_0_whas__5_THEN_m_fifo_1__ETC___d88 = INST_top.INST_m_fifo_1_ehr_wires_0.METH_whas() ? INST_top.INST_m_fifo_1_ehr_wires_0.METH_wget() : INST_top.DEF_def__h16662;
	 INST_top.DEF_x__h14349 = INST_top.DEF_m_fifo_1_ehr_virtual_reg_2_read____d101 || INST_top.DEF_m_fifo_1_ehr_virtual_reg_1_read____d102 ? (tUInt8)0u : INST_top.DEF_IF_m_fifo_1_ehr_wires_0_whas__5_THEN_m_fifo_1__ETC___d88;
	 INST_top.DEF_IF_m_fifo_1_nEmpty_wires_0_whas__5_THEN_m_fifo_ETC___d28 = INST_top.DEF_m_fifo_1_nEmpty_wires_0_whas____d25 ? INST_top.DEF_m_fifo_1_nEmpty_wires_0_wget____d26 : INST_top.DEF_m_fifo_1_nEmpty_ehrReg__h3566;
	 INST_top.DEF_IF_m_fifo_1_ehr_virtual_reg_2_read__01_OR_m_fi_ETC___d142 = (INST_top.DEF_x__h14349) == (tUInt8)1u;
	 INST_top.DEF_CAN_FIRE_RL_m_deq_fifo_1 = !(INST_top.DEF_IF_m_fifo_1_ehr_virtual_reg_2_read__01_OR_m_fi_ETC___d142) || ((INST_top.DEF_m_fifo_1_nEmpty_virtual_reg_2_read____d144 || (INST_top.DEF_m_fifo_1_nEmpty_virtual_reg_1_read____d145 || (INST_top.DEF_m_fifo_1_nEmpty_wires_0_whas____d25 ? !(INST_top.DEF_m_fifo_1_nEmpty_wires_0_wget____d26) : !(INST_top.DEF_m_fifo_1_nEmpty_ehrReg__h3566)))) || INST_top.DEF_IF_m_fifo_1_nEmpty_wires_0_whas__5_THEN_m_fifo_ETC___d28);
	 INST_top.DEF_WILL_FIRE_RL_m_deq_fifo_1 = INST_top.DEF_CAN_FIRE_RL_m_deq_fifo_1 && !(INST_top.DEF_WILL_FIRE_RL_m_enq_fifo_1);
	 if (INST_top.DEF_WILL_FIRE_RL_m_deq_fifo_1)
	   INST_top.RL_m_deq_fifo_1();
	 if (INST_top.DEF_WILL_FIRE_RL_m_clear_fifo_1)
	   INST_top.RL_m_clear_fifo_1();
	 if (INST_top.DEF_WILL_FIRE_RL_m_cycle_stuff)
	   INST_top.RL_m_cycle_stuff();
	 if (INST_top.DEF_WILL_FIRE_RL_m_fifo_1_deqPtr_canonicalize)
	   INST_top.RL_m_fifo_1_deqPtr_canonicalize();
	 if (INST_top.DEF_WILL_FIRE_RL_m_fifo_1_ehr_canonicalize)
	   INST_top.RL_m_fifo_1_ehr_canonicalize();
	 if (INST_top.DEF_WILL_FIRE_RL_m_fifo_1_enqPtr_canonicalize)
	   INST_top.RL_m_fifo_1_enqPtr_canonicalize();
	 if (INST_top.DEF_WILL_FIRE_RL_m_fifo_1_nEmpty_canonicalize)
	   INST_top.RL_m_fifo_1_nEmpty_canonicalize();
	 if (INST_top.DEF_WILL_FIRE_RL_m_fifo_1_nFull_canonicalize)
	   INST_top.RL_m_fifo_1_nFull_canonicalize();
	 if (INST_top.DEF_WILL_FIRE_RL_m_fifo_2_deqPtr_canonicalize)
	   INST_top.RL_m_fifo_2_deqPtr_canonicalize();
	 if (INST_top.DEF_WILL_FIRE_RL_m_fifo_2_ehr_canonicalize)
	   INST_top.RL_m_fifo_2_ehr_canonicalize();
	 if (INST_top.DEF_WILL_FIRE_RL_m_fifo_2_enqPtr_canonicalize)
	   INST_top.RL_m_fifo_2_enqPtr_canonicalize();
	 if (INST_top.DEF_WILL_FIRE_RL_m_fifo_2_nFull_canonicalize)
	   INST_top.RL_m_fifo_2_nFull_canonicalize();
	 if (INST_top.DEF_WILL_FIRE_RL_m_fifo_2_nEmpty_canonicalize)
	   INST_top.RL_m_fifo_2_nEmpty_canonicalize();
	 INST_top.INST_m_fifo_2_ehr_ignored_wires_2.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_ehr_ignored_wires_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_ehr_ignored_wires_0.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_ehr_wires_2.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_ehr_wires_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_ehr_wires_0.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_ehr_ignored_wires_2.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_ehr_ignored_wires_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_ehr_ignored_wires_0.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_ehr_wires_2.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_ehr_wires_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_ehr_wires_0.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_nFull_ignored_wires_2.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_nFull_ignored_wires_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_nFull_ignored_wires_0.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_nFull_wires_2.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_nFull_wires_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_nFull_wires_0.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_nEmpty_ignored_wires_2.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_nEmpty_ignored_wires_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_nEmpty_ignored_wires_0.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_nEmpty_wires_2.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_nEmpty_wires_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_nEmpty_wires_0.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_deqPtr_ignored_wires_2.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_deqPtr_ignored_wires_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_deqPtr_ignored_wires_0.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_deqPtr_wires_2.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_deqPtr_wires_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_deqPtr_wires_0.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_enqPtr_ignored_wires_2.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_enqPtr_ignored_wires_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_enqPtr_ignored_wires_0.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_enqPtr_wires_2.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_enqPtr_wires_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_2_enqPtr_wires_0.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_nFull_ignored_wires_2.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_nFull_ignored_wires_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_nFull_ignored_wires_0.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_nFull_wires_2.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_nFull_wires_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_nFull_wires_0.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_nEmpty_ignored_wires_2.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_nEmpty_ignored_wires_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_nEmpty_ignored_wires_0.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_nEmpty_wires_2.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_nEmpty_wires_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_nEmpty_wires_0.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_deqPtr_ignored_wires_2.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_deqPtr_ignored_wires_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_deqPtr_ignored_wires_0.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_deqPtr_wires_2.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_deqPtr_wires_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_deqPtr_wires_0.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_enqPtr_ignored_wires_2.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_enqPtr_ignored_wires_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_enqPtr_ignored_wires_0.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_enqPtr_wires_2.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_enqPtr_wires_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_m_fifo_1_enqPtr_wires_0.clk((tUInt8)1u, (tUInt8)1u);
	 if (do_reset_ticks(simHdl))
	 {
	   INST_top.INST_m_cycle.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_m_fifo_1_regs_0.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_m_fifo_1_regs_1.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_m_fifo_1_regs_2.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_m_fifo_1_enqPtr_ehrReg.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_m_fifo_1_deqPtr_ehrReg.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_m_fifo_1_nEmpty_ehrReg.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_m_fifo_1_nFull_ehrReg.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_m_fifo_2_regs_0.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_m_fifo_2_regs_1.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_m_fifo_2_regs_2.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_m_fifo_2_enqPtr_ehrReg.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_m_fifo_2_deqPtr_ehrReg.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_m_fifo_2_nEmpty_ehrReg.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_m_fifo_2_nFull_ehrReg.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_m_fifo_1_ehr_ehrReg.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_m_fifo_2_ehr_ehrReg.rst_tick__clk__1((tUInt8)1u);
	 }
       };

/* Model creation/destruction functions */

void MODEL_mkTbBypassScheduling::create_model(tSimStateHdl simHdl, bool master)
{
  sim_hdl = simHdl;
  init_reset_request_counters(sim_hdl);
  mkTbBypassScheduling_instance = new MOD_mkTbBypassScheduling(sim_hdl, "top", NULL);
  bk_get_or_define_clock(sim_hdl, "CLK");
  if (master)
  {
    bk_alter_clock(sim_hdl, bk_get_clock_by_name(sim_hdl, "CLK"), CLK_LOW, false, 0llu, 5llu, 5llu);
    bk_use_default_reset(sim_hdl);
  }
  bk_set_clock_event_fn(sim_hdl,
			bk_get_clock_by_name(sim_hdl, "CLK"),
			schedule_posedge_CLK,
			NULL,
			(tEdgeDirection)(POSEDGE));
  (mkTbBypassScheduling_instance->INST_m_fifo_1_enqPtr_wires_0.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_enqPtr_wires_1.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_enqPtr_wires_2.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_enqPtr_ignored_wires_0.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_enqPtr_ignored_wires_1.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_enqPtr_ignored_wires_2.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_deqPtr_wires_0.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_deqPtr_wires_1.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_deqPtr_wires_2.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_deqPtr_ignored_wires_0.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_deqPtr_ignored_wires_1.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_deqPtr_ignored_wires_2.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_nEmpty_wires_0.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_nEmpty_wires_1.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_nEmpty_wires_2.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_nEmpty_ignored_wires_0.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_nEmpty_ignored_wires_1.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_nEmpty_ignored_wires_2.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_nFull_wires_0.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_nFull_wires_1.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_nFull_wires_2.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_nFull_ignored_wires_0.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_nFull_ignored_wires_1.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_nFull_ignored_wires_2.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_enqPtr_wires_0.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_enqPtr_wires_1.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_enqPtr_wires_2.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_enqPtr_ignored_wires_0.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_enqPtr_ignored_wires_1.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_enqPtr_ignored_wires_2.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_deqPtr_wires_0.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_deqPtr_wires_1.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_deqPtr_wires_2.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_deqPtr_ignored_wires_0.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_deqPtr_ignored_wires_1.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_deqPtr_ignored_wires_2.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_nEmpty_wires_0.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_nEmpty_wires_1.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_nEmpty_wires_2.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_nEmpty_ignored_wires_0.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_nEmpty_ignored_wires_1.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_nEmpty_ignored_wires_2.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_nFull_wires_0.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_nFull_wires_1.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_nFull_wires_2.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_nFull_ignored_wires_0.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_nFull_ignored_wires_1.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_nFull_ignored_wires_2.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_ehr_wires_0.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_ehr_wires_1.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_ehr_wires_2.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_ehr_ignored_wires_0.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_ehr_ignored_wires_1.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_1_ehr_ignored_wires_2.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_ehr_wires_0.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_ehr_wires_1.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_ehr_wires_2.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_ehr_ignored_wires_0.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_ehr_ignored_wires_1.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->INST_m_fifo_2_ehr_ignored_wires_2.set_clk_0)("CLK");
  (mkTbBypassScheduling_instance->set_clk_0)("CLK");
}
void MODEL_mkTbBypassScheduling::destroy_model()
{
  delete mkTbBypassScheduling_instance;
  mkTbBypassScheduling_instance = NULL;
}
void MODEL_mkTbBypassScheduling::reset_model(bool asserted)
{
  (mkTbBypassScheduling_instance->reset_RST_N)(asserted ? (tUInt8)0u : (tUInt8)1u);
}
void * MODEL_mkTbBypassScheduling::get_instance()
{
  return mkTbBypassScheduling_instance;
}

/* Fill in version numbers */
void MODEL_mkTbBypassScheduling::get_version(unsigned int *year,
					     unsigned int *month,
					     char const **annotation,
					     char const **build)
{
  *year = 0u;
  *month = 0u;
  *annotation = NULL;
  *build = "14ff62d";
}

/* Get the model creation time */
time_t MODEL_mkTbBypassScheduling::get_creation_time()
{
  
  /* Wed Jun 28 13:40:06 UTC 2023 */
  return 1687959606llu;
}

/* State dumping function */
void MODEL_mkTbBypassScheduling::dump_state()
{
  (mkTbBypassScheduling_instance->dump_state)(0u);
}

/* VCD dumping functions */
MOD_mkTbBypassScheduling & mkTbBypassScheduling_backing(tSimStateHdl simHdl)
{
  static MOD_mkTbBypassScheduling *instance = NULL;
  if (instance == NULL)
  {
    vcd_set_backing_instance(simHdl, true);
    instance = new MOD_mkTbBypassScheduling(simHdl, "top", NULL);
    vcd_set_backing_instance(simHdl, false);
  }
  return *instance;
}
void MODEL_mkTbBypassScheduling::dump_VCD_defs()
{
  (mkTbBypassScheduling_instance->dump_VCD_defs)(vcd_depth(sim_hdl));
}
void MODEL_mkTbBypassScheduling::dump_VCD(tVCDDumpType dt)
{
  (mkTbBypassScheduling_instance->dump_VCD)(dt,
					    vcd_depth(sim_hdl),
					    mkTbBypassScheduling_backing(sim_hdl));
}

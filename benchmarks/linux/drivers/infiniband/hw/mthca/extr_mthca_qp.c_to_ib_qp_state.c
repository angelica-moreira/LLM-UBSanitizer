#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  enum ib_qp_state { ____Placeholder_ib_qp_state } ib_qp_state ;

/* Variables and functions */
 int IB_QPS_ERR ; 
 int IB_QPS_INIT ; 
 int IB_QPS_RESET ; 
 int IB_QPS_RTR ; 
 int IB_QPS_RTS ; 
 int IB_QPS_SQD ; 
 int IB_QPS_SQE ; 
#define  MTHCA_QP_STATE_DRAINING 135 
#define  MTHCA_QP_STATE_ERR 134 
#define  MTHCA_QP_STATE_INIT 133 
#define  MTHCA_QP_STATE_RST 132 
#define  MTHCA_QP_STATE_RTR 131 
#define  MTHCA_QP_STATE_RTS 130 
#define  MTHCA_QP_STATE_SQD 129 
#define  MTHCA_QP_STATE_SQE 128 

__attribute__((used)) static inline enum ib_qp_state to_ib_qp_state(int mthca_state)
{
	switch (mthca_state) {
	case MTHCA_QP_STATE_RST:      return IB_QPS_RESET;
	case MTHCA_QP_STATE_INIT:     return IB_QPS_INIT;
	case MTHCA_QP_STATE_RTR:      return IB_QPS_RTR;
	case MTHCA_QP_STATE_RTS:      return IB_QPS_RTS;
	case MTHCA_QP_STATE_DRAINING:
	case MTHCA_QP_STATE_SQD:      return IB_QPS_SQD;
	case MTHCA_QP_STATE_SQE:      return IB_QPS_SQE;
	case MTHCA_QP_STATE_ERR:      return IB_QPS_ERR;
	default:                      return -1;
	}
}
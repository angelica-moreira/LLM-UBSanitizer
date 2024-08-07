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
#define  IB_QPS_ERR 133 
#define  IB_QPS_INIT 132 
#define  IB_QPS_RESET 131 
#define  IB_QPS_RTS 130 
#define  IB_QPS_SQD 129 
#define  IB_QPS_SQE 128 
 int IWCH_QP_STATE_CLOSING ; 
 int IWCH_QP_STATE_ERROR ; 
 int IWCH_QP_STATE_IDLE ; 
 int IWCH_QP_STATE_RTS ; 
 int IWCH_QP_STATE_TERMINATE ; 

__attribute__((used)) static inline int iwch_convert_state(enum ib_qp_state ib_state)
{
	switch (ib_state) {
	case IB_QPS_RESET:
	case IB_QPS_INIT:
		return IWCH_QP_STATE_IDLE;
	case IB_QPS_RTS:
		return IWCH_QP_STATE_RTS;
	case IB_QPS_SQD:
		return IWCH_QP_STATE_CLOSING;
	case IB_QPS_SQE:
		return IWCH_QP_STATE_TERMINATE;
	case IB_QPS_ERR:
		return IWCH_QP_STATE_ERROR;
	default:
		return -1;
	}
}
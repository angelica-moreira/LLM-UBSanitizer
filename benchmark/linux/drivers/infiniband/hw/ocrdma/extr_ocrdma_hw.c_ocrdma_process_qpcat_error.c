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
struct ocrdma_qp {int dummy; } ;
struct ocrdma_dev {int dummy; } ;
typedef  enum ib_qp_state { ____Placeholder_ib_qp_state } ib_qp_state ;

/* Variables and functions */
 int /*<<< orphan*/  BUG () ; 
 int IB_QPS_ERR ; 
 int /*<<< orphan*/  ocrdma_qp_state_change (struct ocrdma_qp*,int,int*) ; 

__attribute__((used)) static void ocrdma_process_qpcat_error(struct ocrdma_dev *dev,
				       struct ocrdma_qp *qp)
{
	enum ib_qp_state new_ib_qps = IB_QPS_ERR;
	enum ib_qp_state old_ib_qps;

	if (qp == NULL)
		BUG();
	ocrdma_qp_state_change(qp, new_ib_qps, &old_ib_qps);
}
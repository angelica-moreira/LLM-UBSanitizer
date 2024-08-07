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
struct ib_qp_attr {int /*<<< orphan*/  qp_state; } ;
struct ib_qp {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IB_QPS_SQD ; 
 int /*<<< orphan*/  IB_QP_STATE ; 
 int ib_modify_qp (struct ib_qp*,struct ib_qp_attr*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int iwcm_modify_qp_sqd(struct ib_qp *qp)
{
	struct ib_qp_attr qp_attr;

	BUG_ON(qp == NULL);
	qp_attr.qp_state = IB_QPS_SQD;
	return ib_modify_qp(qp, &qp_attr, IB_QP_STATE);
}
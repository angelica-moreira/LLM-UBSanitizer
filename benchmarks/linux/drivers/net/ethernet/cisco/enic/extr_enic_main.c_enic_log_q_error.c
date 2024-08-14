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
typedef  int u32 ;
struct enic {unsigned int wq_count; unsigned int rq_count; int /*<<< orphan*/  netdev; int /*<<< orphan*/ * rq; int /*<<< orphan*/ * wq; } ;

/* Variables and functions */
 int /*<<< orphan*/  netdev_err (int /*<<< orphan*/ ,char*,unsigned int,int) ; 
 int vnic_rq_error_status (int /*<<< orphan*/ *) ; 
 int vnic_wq_error_status (int /*<<< orphan*/ *) ; 

__attribute__((used)) static bool enic_log_q_error(struct enic *enic)
{
	unsigned int i;
	u32 error_status;
	bool err = false;

	for (i = 0; i < enic->wq_count; i++) {
		error_status = vnic_wq_error_status(&enic->wq[i]);
		err |= error_status;
		if (error_status)
			netdev_err(enic->netdev, "WQ[%d] error_status %d\n",
				i, error_status);
	}

	for (i = 0; i < enic->rq_count; i++) {
		error_status = vnic_rq_error_status(&enic->rq[i]);
		err |= error_status;
		if (error_status)
			netdev_err(enic->netdev, "RQ[%d] error_status %d\n",
				i, error_status);
	}

	return err;
}
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
struct qed_hwfn {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  IS_PF_SRIOV (struct qed_hwfn*) ; 
 int /*<<< orphan*/  IS_PF_SRIOV_ALLOC (struct qed_hwfn*) ; 
 int /*<<< orphan*/  qed_iov_setup_vfdb (struct qed_hwfn*) ; 

void qed_iov_setup(struct qed_hwfn *p_hwfn)
{
	if (!IS_PF_SRIOV(p_hwfn) || !IS_PF_SRIOV_ALLOC(p_hwfn))
		return;

	qed_iov_setup_vfdb(p_hwfn);
}
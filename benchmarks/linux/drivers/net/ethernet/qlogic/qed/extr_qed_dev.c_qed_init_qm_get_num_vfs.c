#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u16 ;
struct qed_hwfn {TYPE_2__* cdev; } ;
struct TYPE_4__ {TYPE_1__* p_iov_info; } ;
struct TYPE_3__ {int /*<<< orphan*/  total_vfs; } ;

/* Variables and functions */
 scalar_t__ IS_QED_SRIOV (TYPE_2__*) ; 

__attribute__((used)) static u16 qed_init_qm_get_num_vfs(struct qed_hwfn *p_hwfn)
{
	return IS_QED_SRIOV(p_hwfn->cdev) ?
	       p_hwfn->cdev->p_iov_info->total_vfs : 0;
}
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
struct qed_hwfn {scalar_t__ db_bar_no_edpm; scalar_t__ dcbx_no_edpm; } ;

/* Variables and functions */

bool qed_edpm_enabled(struct qed_hwfn *p_hwfn)
{
	if (p_hwfn->dcbx_no_edpm || p_hwfn->db_bar_no_edpm)
		return false;

	return true;
}
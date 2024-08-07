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
struct qm_mc {scalar_t__ state; } ;
struct qm_portal {struct qm_mc mc; } ;

/* Variables and functions */
 int /*<<< orphan*/  DPAA_ASSERT (int) ; 
 int /*<<< orphan*/  pr_crit (char*) ; 
 scalar_t__ qman_mc_idle ; 

__attribute__((used)) static inline void qm_mc_finish(struct qm_portal *portal)
{
#ifdef CONFIG_FSL_DPAA_CHECKING
	struct qm_mc *mc = &portal->mc;

	DPAA_ASSERT(mc->state == qman_mc_idle);
	if (mc->state != qman_mc_idle)
		pr_crit("Losing incomplete MC command\n");
#endif
}
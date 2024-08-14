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
typedef  int /*<<< orphan*/  u32 ;
struct qm_portal {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  QM_REG_DQRR_VDQCR ; 
 int /*<<< orphan*/  qm_out (struct qm_portal*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void qm_dqrr_vdqcr_set(struct qm_portal *portal, u32 vdqcr)
{
	qm_out(portal, QM_REG_DQRR_VDQCR, vdqcr);
}
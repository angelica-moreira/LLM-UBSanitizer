#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_2__ {int /*<<< orphan*/  ioc_fail_sync; } ;
struct bfa_ioc {TYPE_1__ ioc_regs; } ;

/* Variables and functions */
 int bfa_ioc_ct_sync_reqd_pos (struct bfa_ioc*) ; 
 int readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
bfa_ioc_ct_sync_join(struct bfa_ioc *ioc)
{
	u32 r32 = readl(ioc->ioc_regs.ioc_fail_sync);
	u32 sync_pos = bfa_ioc_ct_sync_reqd_pos(ioc);

	writel((r32 | sync_pos), ioc->ioc_regs.ioc_fail_sync);
}
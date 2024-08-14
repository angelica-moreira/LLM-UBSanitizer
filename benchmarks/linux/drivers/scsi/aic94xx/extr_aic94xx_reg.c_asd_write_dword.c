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
typedef  int /*<<< orphan*/  u32 ;
struct asd_ha_struct {TYPE_1__* io_handle; int /*<<< orphan*/  iospace; } ;
struct TYPE_2__ {scalar_t__ addr; } ;

/* Variables and functions */
 int /*<<< orphan*/  outl (int /*<<< orphan*/ ,unsigned long) ; 
 scalar_t__ unlikely (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wmb () ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void asd_write_dword(struct asd_ha_struct *asd_ha,
			    unsigned long offs, u32 val)
{
	if (unlikely(asd_ha->iospace))
		outl(val,
		     (unsigned long)asd_ha->io_handle[0].addr + (offs & 0xFF));
	else
		writel(val, asd_ha->io_handle[0].addr + offs);
	wmb();
}
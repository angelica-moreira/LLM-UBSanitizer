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
struct net_device {int dummy; } ;

/* Variables and functions */
 scalar_t__ ETHER1_RAM ; 
 int /*<<< orphan*/  REG_PAGE ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  writeb (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writew (unsigned short,scalar_t__) ; 

__attribute__((used)) static inline void
ether1_outw_p (struct net_device *dev, unsigned short val, int addr, int svflgs)
{
	unsigned long flags;

	if (svflgs)
		local_irq_save (flags);

	writeb(addr >> 12, REG_PAGE);
	writew(val, ETHER1_RAM + ((addr & 4095) << 1));
	if (svflgs)
		local_irq_restore (flags);
}
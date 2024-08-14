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

/* Variables and functions */
 unsigned int cookie_build_irq (int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ *) ; 
 unsigned int cookie_exists (int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  sun4v_virq ; 

__attribute__((used)) static unsigned int sun4v_build_cookie(u32 devhandle, unsigned int devino)
{
	unsigned int irq;

	irq = cookie_exists(devhandle, devino);
	if (irq)
		goto out;

	irq = cookie_build_irq(devhandle, devino, &sun4v_virq);

out:
	return irq;
}
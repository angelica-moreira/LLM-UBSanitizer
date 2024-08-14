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
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/ * enable ; 
 scalar_t__* isapnp ; 

__attribute__((used)) static int snd_interwave_isa_match(struct device *pdev,
				   unsigned int dev)
{
	if (!enable[dev])
		return 0;
#ifdef CONFIG_PNP
	if (isapnp[dev])
		return 0;
#endif
	return 1;
}
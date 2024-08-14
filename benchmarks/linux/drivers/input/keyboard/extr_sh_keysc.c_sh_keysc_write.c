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
struct sh_keysc_priv {scalar_t__ iomem_base; } ;

/* Variables and functions */
 int /*<<< orphan*/  iowrite16 (unsigned long,scalar_t__) ; 

__attribute__((used)) static void sh_keysc_write(struct sh_keysc_priv *p, int reg_nr,
			   unsigned long value)
{
	iowrite16(value, p->iomem_base + (reg_nr << 2));
}
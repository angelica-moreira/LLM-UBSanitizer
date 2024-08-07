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
struct TYPE_2__ {scalar_t__ base; } ;
struct omap2_onenand {TYPE_1__ onenand; } ;

/* Variables and functions */
 unsigned short readw (scalar_t__) ; 

__attribute__((used)) static inline unsigned short read_reg(struct omap2_onenand *c, int reg)
{
	return readw(c->onenand.base + reg);
}
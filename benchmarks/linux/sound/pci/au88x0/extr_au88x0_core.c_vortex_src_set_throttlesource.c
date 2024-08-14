#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  mmio; } ;
typedef  TYPE_1__ vortex_t ;

/* Variables and functions */
 int /*<<< orphan*/  VORTEX_SRC_SOURCE ; 
 int hwread (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hwwrite (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void
vortex_src_set_throttlesource(vortex_t * vortex, unsigned char src, int en)
{
	int temp;

	temp = hwread(vortex->mmio, VORTEX_SRC_SOURCE);
	if (en)
		temp |= 1 << src;
	else
		temp &= ~(1 << src);
	hwwrite(vortex->mmio, VORTEX_SRC_SOURCE, temp);
}
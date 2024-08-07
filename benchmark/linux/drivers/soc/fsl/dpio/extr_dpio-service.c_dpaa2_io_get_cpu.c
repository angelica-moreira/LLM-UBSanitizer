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
struct TYPE_2__ {int cpu; } ;
struct dpaa2_io {TYPE_1__ dpio_desc; } ;

/* Variables and functions */

int dpaa2_io_get_cpu(struct dpaa2_io *d)
{
	return d->dpio_desc.cpu;
}
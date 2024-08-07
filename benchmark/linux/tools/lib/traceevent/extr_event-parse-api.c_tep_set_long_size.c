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
struct tep_handle {int long_size; } ;

/* Variables and functions */

void tep_set_long_size(struct tep_handle *tep, int long_size)
{
	if (tep)
		tep->long_size = long_size;
}
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
struct bc_state {int /*<<< orphan*/  corrupted; scalar_t__ ignore; } ;

/* Variables and functions */

void gigaset_isdn_rcv_err(struct bc_state *bcs)
{
	/* if currently ignoring packets, just count down */
	if (bcs->ignore) {
		bcs->ignore--;
		return;
	}

	/* update statistics */
	bcs->corrupted++;

	/* ToDo: signal error -> LL */
}
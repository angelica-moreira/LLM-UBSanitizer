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
struct bc_state {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  gigaset_bchannel_up (struct bc_state*) ; 

__attribute__((used)) static int gigaset_init_bchannel(struct bc_state *bcs)
{
	/* nothing to do for M10x */
	gigaset_bchannel_up(bcs);
	return 0;
}
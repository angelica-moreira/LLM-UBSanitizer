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
struct pn533 {int poll_mod_curr; int poll_mod_count; } ;

/* Variables and functions */

__attribute__((used)) static inline void pn533_poll_next_mod(struct pn533 *dev)
{
	dev->poll_mod_curr = (dev->poll_mod_curr + 1) % dev->poll_mod_count;
}
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

/* Variables and functions */
 int /*<<< orphan*/  atomic_long_set (int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ lazy_max_pages () ; 
 int /*<<< orphan*/  vmap_lazy_nr ; 

void set_iounmap_nonlazy(void)
{
	atomic_long_set(&vmap_lazy_nr, lazy_max_pages()+1);
}
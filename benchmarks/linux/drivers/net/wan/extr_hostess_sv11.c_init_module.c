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
 int ENODEV ; 
 int /*<<< orphan*/  io ; 
 int /*<<< orphan*/  irq ; 
 int /*<<< orphan*/ * sv11_init (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * sv11_unit ; 

int init_module(void)
{
	if ((sv11_unit = sv11_init(io, irq)) == NULL)
		return -ENODEV;
	return 0;
}
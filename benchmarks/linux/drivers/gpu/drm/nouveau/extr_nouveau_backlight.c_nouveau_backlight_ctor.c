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
 int /*<<< orphan*/  bl_ida ; 
 int /*<<< orphan*/  ida_init (int /*<<< orphan*/ *) ; 

void
nouveau_backlight_ctor(void)
{
	ida_init(&bl_ida);
}
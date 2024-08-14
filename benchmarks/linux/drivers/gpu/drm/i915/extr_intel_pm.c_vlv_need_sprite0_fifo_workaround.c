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
 unsigned int BIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLANE_SPRITE0 ; 
 int /*<<< orphan*/  PLANE_SPRITE1 ; 

__attribute__((used)) static bool vlv_need_sprite0_fifo_workaround(unsigned int active_planes)
{
	return (active_planes & (BIT(PLANE_SPRITE0) |
				 BIT(PLANE_SPRITE1))) == BIT(PLANE_SPRITE1);
}
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
 int gfx_v9_0_hw_init (void*) ; 

__attribute__((used)) static int gfx_v9_0_resume(void *handle)
{
	return gfx_v9_0_hw_init(handle);
}
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
 int exercise_ggtt (void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lowlevel_hole ; 

__attribute__((used)) static int igt_ggtt_lowlevel(void *arg)
{
	return exercise_ggtt(arg, lowlevel_hole);
}
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
 int exercise_ppgtt (void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  shrink_boom ; 

__attribute__((used)) static int igt_ppgtt_shrink_boom(void *arg)
{
	return exercise_ppgtt(arg, shrink_boom);
}
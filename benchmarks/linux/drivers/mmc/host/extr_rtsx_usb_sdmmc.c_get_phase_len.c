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
typedef  int /*<<< orphan*/  u32 ;

/* Variables and functions */
 int MAX_PHASE ; 
 scalar_t__ get_phase_point (int /*<<< orphan*/ ,unsigned int) ; 

__attribute__((used)) static int get_phase_len(u32 phase_map, unsigned int idx)
{
	int i;

	for (i = 0; i < MAX_PHASE + 1; i++) {
		if (get_phase_point(phase_map, idx + i) == 0)
			return i;
	}
	return MAX_PHASE + 1;
}
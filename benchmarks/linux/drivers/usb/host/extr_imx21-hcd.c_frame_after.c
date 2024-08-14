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
typedef  scalar_t__ s16 ;

/* Variables and functions */

__attribute__((used)) static inline int frame_after(int frame, int after)
{
	/* handle wrapping like jiffies time_afer */
	return (s16)((s16)after - (s16)frame) < 0;
}
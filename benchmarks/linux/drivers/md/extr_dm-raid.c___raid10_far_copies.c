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
 int RAID10_FAR_COPIES_SHIFT ; 
 unsigned int __raid10_near_copies (int) ; 

__attribute__((used)) static unsigned int __raid10_far_copies(int layout)
{
	return __raid10_near_copies(layout >> RAID10_FAR_COPIES_SHIFT);
}
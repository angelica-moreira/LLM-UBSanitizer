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
 unsigned int ALIGN (unsigned int,int) ; 

__attribute__((used)) static inline unsigned int _sdio_align_size(unsigned int sz)
{
	/*
	 * FIXME: We don't have a system for the controller to tell
	 * the core about its problems yet, so for now we just 32-bit
	 * align the size.
	 */
	return ALIGN(sz, 4);
}
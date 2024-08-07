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
 unsigned int CR_REQS (unsigned int) ; 

__attribute__((used)) static unsigned int mite_drq_reqs(unsigned int drq_line)
{
	/* This also works on m-series when using channels (drq_line) 4 or 5. */
	return CR_REQS((drq_line & 0x3) | 0x4);
}
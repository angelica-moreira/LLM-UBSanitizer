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
 unsigned long IDENTITY_FRAME (unsigned long) ; 
 unsigned int P2M_PER_PAGE ; 

__attribute__((used)) static void p2m_init_identity(unsigned long *p2m, unsigned long pfn)
{
	unsigned i;

	for (i = 0; i < P2M_PER_PAGE; i++)
		p2m[i] = IDENTITY_FRAME(pfn + i);
}
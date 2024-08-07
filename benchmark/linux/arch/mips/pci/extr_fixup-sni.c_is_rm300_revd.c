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
 scalar_t__ PCIMT_CSMSR ; 

__attribute__((used)) static inline int is_rm300_revd(void)
{
	unsigned char csmsr = *(volatile unsigned char *)PCIMT_CSMSR;

	return (csmsr & 0xa0) == 0x20;
}
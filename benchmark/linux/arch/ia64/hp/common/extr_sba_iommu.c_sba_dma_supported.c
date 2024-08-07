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
typedef  int u64 ;
struct device {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static int sba_dma_supported (struct device *dev, u64 mask)
{
	/* make sure it's at least 32bit capable */
	return ((mask & 0xFFFFFFFFUL) == 0xFFFFFFFFUL);
}
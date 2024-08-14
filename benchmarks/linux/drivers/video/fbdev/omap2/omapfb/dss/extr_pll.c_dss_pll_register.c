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
struct dss_pll {int dummy; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct dss_pll**) ; 
 int EBUSY ; 
 struct dss_pll** dss_plls ; 

int dss_pll_register(struct dss_pll *pll)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(dss_plls); ++i) {
		if (!dss_plls[i]) {
			dss_plls[i] = pll;
			return 0;
		}
	}

	return -EBUSY;
}
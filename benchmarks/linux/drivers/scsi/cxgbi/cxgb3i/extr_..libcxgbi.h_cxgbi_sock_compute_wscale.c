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

__attribute__((used)) static inline unsigned int cxgbi_sock_compute_wscale(unsigned int win)
{
	unsigned int wscale = 0;

	while (wscale < 14 && (65535 << wscale) < win)
		wscale++;
	return wscale;
}
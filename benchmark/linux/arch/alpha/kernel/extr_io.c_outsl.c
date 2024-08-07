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
 int /*<<< orphan*/  ioport_map (unsigned long,int) ; 
 int /*<<< orphan*/  iowrite32_rep (int /*<<< orphan*/ ,void const*,unsigned long) ; 

void outsl(unsigned long port, const void *src, unsigned long count)
{
	iowrite32_rep(ioport_map(port, 4), src, count);
}
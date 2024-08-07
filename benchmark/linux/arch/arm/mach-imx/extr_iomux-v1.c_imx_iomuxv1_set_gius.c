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
 int /*<<< orphan*/  MXC_GIUS (unsigned int) ; 
 int /*<<< orphan*/  imx_iomuxv1_rmwl (int /*<<< orphan*/ ,unsigned long,unsigned long) ; 

__attribute__((used)) static inline void imx_iomuxv1_set_gius(
		unsigned int port, unsigned int pin, int inuse)
{
	unsigned long mask = 1 << pin;

	imx_iomuxv1_rmwl(MXC_GIUS(port), mask, inuse ? mask : 0);
}
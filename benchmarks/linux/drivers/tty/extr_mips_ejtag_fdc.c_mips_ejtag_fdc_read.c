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
struct mips_ejtag_fdc_tty {scalar_t__ reg; } ;

/* Variables and functions */
 unsigned int __raw_readl (scalar_t__) ; 

__attribute__((used)) static inline unsigned int mips_ejtag_fdc_read(struct mips_ejtag_fdc_tty *priv,
					       unsigned int offs)
{
	return __raw_readl(priv->reg + offs);
}
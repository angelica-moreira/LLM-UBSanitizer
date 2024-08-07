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
struct mtk_hdmi_ddc {scalar_t__ regs; } ;

/* Variables and functions */
 unsigned int readl (scalar_t__) ; 

__attribute__((used)) static inline unsigned int sif_read_mask(struct mtk_hdmi_ddc *ddc,
					 unsigned int offset, unsigned int mask,
					 unsigned int shift)
{
	return (readl(ddc->regs + offset) & mask) >> shift;
}
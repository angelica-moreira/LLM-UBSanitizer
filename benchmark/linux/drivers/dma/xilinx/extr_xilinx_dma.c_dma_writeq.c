#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
typedef  scalar_t__ u32 ;
struct xilinx_dma_chan {scalar_t__ ctrl_offset; TYPE_1__* xdev; } ;
struct TYPE_2__ {scalar_t__ regs; } ;

/* Variables and functions */
 int /*<<< orphan*/  lo_hi_writeq (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static inline void dma_writeq(struct xilinx_dma_chan *chan, u32 reg, u64 value)
{
	lo_hi_writeq(value, chan->xdev->regs + chan->ctrl_offset + reg);
}
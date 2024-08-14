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
typedef  int u8 ;
struct ioatdma_chan {scalar_t__ reg_base; TYPE_1__* ioat_dma; } ;
struct TYPE_2__ {int version; } ;

/* Variables and functions */
 scalar_t__ IOAT_CHANCMD_OFFSET (int) ; 
 int IOAT_CHANCMD_RESET ; 
 int readb (scalar_t__) ; 

__attribute__((used)) static inline bool ioat_reset_pending(struct ioatdma_chan *ioat_chan)
{
	u8 ver = ioat_chan->ioat_dma->version;
	u8 cmd;

	cmd = readb(ioat_chan->reg_base + IOAT_CHANCMD_OFFSET(ver));
	return (cmd & IOAT_CHANCMD_RESET) == IOAT_CHANCMD_RESET;
}
#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  mmio; TYPE_2__* dma_wt; } ;
typedef  TYPE_1__ vortex_t ;
struct TYPE_6__ {int fifo_status; int /*<<< orphan*/  fifo_enabled; int /*<<< orphan*/  dma_unknown; int /*<<< orphan*/  dma_ctrl; } ;
typedef  TYPE_2__ stream_t ;

/* Variables and functions */
#define  FIFO_PAUSE 129 
 int FIFO_START ; 
#define  FIFO_STOP 128 
 int /*<<< orphan*/  VORTEX_WTDMA_CTRL ; 
 int /*<<< orphan*/  hwwrite (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vortex_fifo_setwtctrl (TYPE_1__*,int,int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void vortex_wtdma_resumefifo(vortex_t * vortex, int wtdma)
{
	stream_t *dma = &vortex->dma_wt[wtdma];

	int this_8 = 0, this_4 = 0;
	switch (dma->fifo_status) {
	case FIFO_STOP:
		hwwrite(vortex->mmio, VORTEX_WTDMA_CTRL + (wtdma << 2),
			dma->dma_ctrl);
		vortex_fifo_setwtctrl(vortex, wtdma, dma->dma_unknown,
				      this_4, this_8,
				      dma->fifo_enabled ? 1 : 0, 0);
		break;
	case FIFO_PAUSE:
		vortex_fifo_setwtctrl(vortex, wtdma, dma->dma_unknown,
				      this_4, this_8,
				      dma->fifo_enabled ? 1 : 0, 0);
		break;
	}
	dma->fifo_status = FIFO_START;
}
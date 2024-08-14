#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct scsi_pointer {int this_residual; } ;
struct device {int dummy; } ;
struct TYPE_3__ {int dma; } ;
struct TYPE_4__ {TYPE_1__ scsi; } ;
struct cumanascsi2_info {scalar_t__ base; int /*<<< orphan*/ * sg; TYPE_2__ info; } ;
struct Scsi_Host {scalar_t__ hostdata; } ;
typedef  scalar_t__ fasdmatype_t ;
typedef  scalar_t__ fasdmadir_t ;

/* Variables and functions */
 int ALATCH_DIS_BIT32 ; 
 int ALATCH_DIS_DMA ; 
 int ALATCH_DMA_IN ; 
 int ALATCH_DMA_OUT ; 
 int ALATCH_ENA_DMA ; 
 scalar_t__ CUMANASCSI2_ALATCH ; 
 int DMA_FROM_DEVICE ; 
 int DMA_MODE_READ ; 
 int DMA_MODE_WRITE ; 
 scalar_t__ DMA_OUT ; 
 int DMA_TO_DEVICE ; 
 int NO_DMA ; 
 int /*<<< orphan*/  NR_SG ; 
 int copy_SCp_to_sg (int /*<<< orphan*/ *,struct scsi_pointer*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  disable_dma (int) ; 
 int /*<<< orphan*/  dma_map_sg (struct device*,int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  enable_dma (int) ; 
 scalar_t__ fasdma_pio ; 
 scalar_t__ fasdma_real_all ; 
 struct device* scsi_get_device (struct Scsi_Host*) ; 
 int /*<<< orphan*/  set_dma_mode (int,int) ; 
 int /*<<< orphan*/  set_dma_sg (int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  writeb (int,scalar_t__) ; 

__attribute__((used)) static fasdmatype_t
cumanascsi_2_dma_setup(struct Scsi_Host *host, struct scsi_pointer *SCp,
		       fasdmadir_t direction, fasdmatype_t min_type)
{
	struct cumanascsi2_info *info = (struct cumanascsi2_info *)host->hostdata;
	struct device *dev = scsi_get_device(host);
	int dmach = info->info.scsi.dma;

	writeb(ALATCH_DIS_DMA, info->base + CUMANASCSI2_ALATCH);

	if (dmach != NO_DMA &&
	    (min_type == fasdma_real_all || SCp->this_residual >= 512)) {
		int bufs, map_dir, dma_dir, alatch_dir;

		bufs = copy_SCp_to_sg(&info->sg[0], SCp, NR_SG);

		if (direction == DMA_OUT)
			map_dir = DMA_TO_DEVICE,
			dma_dir = DMA_MODE_WRITE,
			alatch_dir = ALATCH_DMA_OUT;
		else
			map_dir = DMA_FROM_DEVICE,
			dma_dir = DMA_MODE_READ,
			alatch_dir = ALATCH_DMA_IN;

		dma_map_sg(dev, info->sg, bufs, map_dir);

		disable_dma(dmach);
		set_dma_sg(dmach, info->sg, bufs);
		writeb(alatch_dir, info->base + CUMANASCSI2_ALATCH);
		set_dma_mode(dmach, dma_dir);
		enable_dma(dmach);
		writeb(ALATCH_ENA_DMA, info->base + CUMANASCSI2_ALATCH);
		writeb(ALATCH_DIS_BIT32, info->base + CUMANASCSI2_ALATCH);
		return fasdma_real_all;
	}

	/*
	 * If we're not doing DMA,
	 *  we'll do pseudo DMA
	 */
	return fasdma_pio;
}
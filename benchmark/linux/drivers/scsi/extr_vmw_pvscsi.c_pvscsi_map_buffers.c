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
struct scsi_cmnd {int /*<<< orphan*/  sc_data_direction; } ;
struct scatterlist {int dummy; } ;
struct pvscsi_ctx {void* dataPA; void* sglPA; struct scatterlist* sgl; } ;
struct pvscsi_adapter {TYPE_1__* dev; } ;
struct PVSCSIRingReqDesc {unsigned int dataLen; void* dataAddr; int /*<<< orphan*/  flags; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMA_TO_DEVICE ; 
 int ENOMEM ; 
 int /*<<< orphan*/  KERN_ERR ; 
 int /*<<< orphan*/  PVSCSI_FLAG_CMD_WITH_SG_LIST ; 
 unsigned int SGL_SIZE ; 
 void* dma_map_single (int /*<<< orphan*/ *,struct scatterlist*,unsigned int,int /*<<< orphan*/ ) ; 
 scalar_t__ dma_mapping_error (int /*<<< orphan*/ *,void*) ; 
 int /*<<< orphan*/  pvscsi_create_sg (struct pvscsi_ctx*,struct scatterlist*,int) ; 
 int /*<<< orphan*/  scmd_printk (int /*<<< orphan*/ ,struct scsi_cmnd*,char*) ; 
 unsigned int scsi_bufflen (struct scsi_cmnd*) ; 
 int scsi_dma_map (struct scsi_cmnd*) ; 
 int /*<<< orphan*/  scsi_dma_unmap (struct scsi_cmnd*) ; 
 unsigned int scsi_sg_count (struct scsi_cmnd*) ; 
 struct scatterlist* scsi_sglist (struct scsi_cmnd*) ; 
 void* sg_dma_address (struct scatterlist*) ; 

__attribute__((used)) static int pvscsi_map_buffers(struct pvscsi_adapter *adapter,
			      struct pvscsi_ctx *ctx, struct scsi_cmnd *cmd,
			      struct PVSCSIRingReqDesc *e)
{
	unsigned count;
	unsigned bufflen = scsi_bufflen(cmd);
	struct scatterlist *sg;

	e->dataLen = bufflen;
	e->dataAddr = 0;
	if (bufflen == 0)
		return 0;

	sg = scsi_sglist(cmd);
	count = scsi_sg_count(cmd);
	if (count != 0) {
		int segs = scsi_dma_map(cmd);

		if (segs == -ENOMEM) {
			scmd_printk(KERN_ERR, cmd,
				    "vmw_pvscsi: Failed to map cmd sglist for DMA.\n");
			return -ENOMEM;
		} else if (segs > 1) {
			pvscsi_create_sg(ctx, sg, segs);

			e->flags |= PVSCSI_FLAG_CMD_WITH_SG_LIST;
			ctx->sglPA = dma_map_single(&adapter->dev->dev,
					ctx->sgl, SGL_SIZE, DMA_TO_DEVICE);
			if (dma_mapping_error(&adapter->dev->dev, ctx->sglPA)) {
				scmd_printk(KERN_ERR, cmd,
					    "vmw_pvscsi: Failed to map ctx sglist for DMA.\n");
				scsi_dma_unmap(cmd);
				ctx->sglPA = 0;
				return -ENOMEM;
			}
			e->dataAddr = ctx->sglPA;
		} else
			e->dataAddr = sg_dma_address(sg);
	} else {
		/*
		 * In case there is no S/G list, scsi_sglist points
		 * directly to the buffer.
		 */
		ctx->dataPA = dma_map_single(&adapter->dev->dev, sg, bufflen,
					     cmd->sc_data_direction);
		if (dma_mapping_error(&adapter->dev->dev, ctx->dataPA)) {
			scmd_printk(KERN_ERR, cmd,
				    "vmw_pvscsi: Failed to map direct data buffer for DMA.\n");
			return -ENOMEM;
		}
		e->dataAddr = ctx->dataPA;
	}

	return 0;
}
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
struct vnic_wq_buf {int sop; unsigned int len; int /*<<< orphan*/  index; struct vnic_wq_buf* next; int /*<<< orphan*/  dma_addr; void* os_buf; } ;
struct TYPE_4__ {int /*<<< orphan*/  desc_avail; } ;
struct vnic_wq {TYPE_2__ ring; struct vnic_wq_buf* to_use; TYPE_1__* ctrl; } ;
typedef  int /*<<< orphan*/  dma_addr_t ;
struct TYPE_3__ {int /*<<< orphan*/  posted_index; } ;

/* Variables and functions */
 int /*<<< orphan*/  iowrite32 (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wmb () ; 

__attribute__((used)) static inline void vnic_wq_post(struct vnic_wq *wq,
	void *os_buf, dma_addr_t dma_addr,
	unsigned int len, int sop, int eop)
{
	struct vnic_wq_buf *buf = wq->to_use;

	buf->sop = sop;
	buf->os_buf = eop ? os_buf : NULL;
	buf->dma_addr = dma_addr;
	buf->len = len;

	buf = buf->next;
	if (eop) {
		/* Adding write memory barrier prevents compiler and/or CPU
		 * reordering, thus avoiding descriptor posting before
		 * descriptor is initialized. Otherwise, hardware can read
		 * stale descriptor fields.
		 */
		wmb();
		iowrite32(buf->index, &wq->ctrl->posted_index);
	}
	wq->to_use = buf;

	wq->ring.desc_avail--;
}
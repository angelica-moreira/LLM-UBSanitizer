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
struct timer_list {int dummy; } ;
struct au0828_dmaqueue {int dummy; } ;
struct TYPE_3__ {struct au0828_buffer* vbi_buf; } ;
struct au0828_dev {int vbi_timeout_running; int /*<<< orphan*/  slock; int /*<<< orphan*/  vbi_timeout; TYPE_1__ isoc_ctl; struct au0828_dmaqueue vbiq; } ;
struct TYPE_4__ {int /*<<< orphan*/  vb2_buf; } ;
struct au0828_buffer {int /*<<< orphan*/  length; TYPE_2__ vb; } ;

/* Variables and functions */
 int HZ ; 
 int /*<<< orphan*/  buffer_filled (struct au0828_dev*,struct au0828_dmaqueue*,struct au0828_buffer*) ; 
 struct au0828_dev* dev ; 
 struct au0828_dev* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  memset (unsigned char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 unsigned char* vb2_plane_vaddr (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vbi_get_next_buf (struct au0828_dmaqueue*,struct au0828_buffer**) ; 
 int /*<<< orphan*/  vbi_timeout ; 

__attribute__((used)) static void au0828_vbi_buffer_timeout(struct timer_list *t)
{
	struct au0828_dev *dev = from_timer(dev, t, vbi_timeout);
	struct au0828_dmaqueue *dma_q = &dev->vbiq;
	struct au0828_buffer *buf;
	unsigned char *vbi_data;
	unsigned long flags = 0;

	spin_lock_irqsave(&dev->slock, flags);

	buf = dev->isoc_ctl.vbi_buf;
	if (buf != NULL) {
		vbi_data = vb2_plane_vaddr(&buf->vb.vb2_buf, 0);
		memset(vbi_data, 0x00, buf->length);
		buffer_filled(dev, dma_q, buf);
	}
	vbi_get_next_buf(dma_q, &buf);

	if (dev->vbi_timeout_running == 1)
		mod_timer(&dev->vbi_timeout, jiffies + (HZ / 10));
	spin_unlock_irqrestore(&dev->slock, flags);
}
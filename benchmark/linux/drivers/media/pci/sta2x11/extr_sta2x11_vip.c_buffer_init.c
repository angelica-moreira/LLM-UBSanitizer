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
struct vip_buffer {int /*<<< orphan*/  list; int /*<<< orphan*/  dma; } ;
struct vb2_v4l2_buffer {int dummy; } ;
struct vb2_buffer {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 struct vb2_v4l2_buffer* to_vb2_v4l2_buffer (struct vb2_buffer*) ; 
 struct vip_buffer* to_vip_buffer (struct vb2_v4l2_buffer*) ; 
 int /*<<< orphan*/  vb2_dma_contig_plane_dma_addr (struct vb2_buffer*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int buffer_init(struct vb2_buffer *vb)
{
	struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
	struct vip_buffer *vip_buf = to_vip_buffer(vbuf);

	vip_buf->dma = vb2_dma_contig_plane_dma_addr(vb, 0);
	INIT_LIST_HEAD(&vip_buf->list);
	return 0;
}
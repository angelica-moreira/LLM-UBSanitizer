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
struct vb2_vmalloc_buf {scalar_t__ vaddr; int /*<<< orphan*/  dbuf; } ;

/* Variables and functions */
 int /*<<< orphan*/  dma_buf_vunmap (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  kfree (struct vb2_vmalloc_buf*) ; 

__attribute__((used)) static void vb2_vmalloc_detach_dmabuf(void *mem_priv)
{
	struct vb2_vmalloc_buf *buf = mem_priv;

	if (buf->vaddr)
		dma_buf_vunmap(buf->dbuf, buf->vaddr);

	kfree(buf);
}
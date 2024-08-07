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
struct videobuf_dma_contig_memory {void* vaddr; int /*<<< orphan*/  magic; } ;
struct videobuf_buffer {struct videobuf_dma_contig_memory* priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  MAGIC_CHECK (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAGIC_DC_MEM ; 

__attribute__((used)) static void *__videobuf_to_vaddr(struct videobuf_buffer *buf)
{
	struct videobuf_dma_contig_memory *mem = buf->priv;

	BUG_ON(!mem);
	MAGIC_CHECK(mem->magic, MAGIC_DC_MEM);

	return mem->vaddr;
}
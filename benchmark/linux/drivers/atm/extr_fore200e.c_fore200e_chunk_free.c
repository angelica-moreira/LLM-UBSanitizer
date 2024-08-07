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
struct fore200e {int /*<<< orphan*/  dev; } ;
struct chunk {int /*<<< orphan*/  alloc_addr; int /*<<< orphan*/  direction; int /*<<< orphan*/  dma_size; int /*<<< orphan*/  dma_addr; } ;

/* Variables and functions */
 int /*<<< orphan*/  dma_unmap_single (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
fore200e_chunk_free(struct fore200e* fore200e, struct chunk* chunk)
{
    dma_unmap_single(fore200e->dev, chunk->dma_addr, chunk->dma_size,
		     chunk->direction);
    kfree(chunk->alloc_addr);
}
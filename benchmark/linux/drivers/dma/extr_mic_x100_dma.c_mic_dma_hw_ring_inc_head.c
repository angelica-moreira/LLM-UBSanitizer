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
struct mic_dma_chan {int /*<<< orphan*/  head; } ;

/* Variables and functions */
 int /*<<< orphan*/  mic_dma_hw_ring_inc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void mic_dma_hw_ring_inc_head(struct mic_dma_chan *ch)
{
	ch->head = mic_dma_hw_ring_inc(ch->head);
}
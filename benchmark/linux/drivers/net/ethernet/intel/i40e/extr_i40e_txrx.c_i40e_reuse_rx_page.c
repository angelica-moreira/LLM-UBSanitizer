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
typedef  size_t u16 ;
struct i40e_rx_buffer {int /*<<< orphan*/ * page; int /*<<< orphan*/  pagecnt_bias; int /*<<< orphan*/  page_offset; int /*<<< orphan*/  dma; } ;
struct TYPE_2__ {int /*<<< orphan*/  page_reuse_count; } ;
struct i40e_ring {size_t next_to_alloc; size_t count; TYPE_1__ rx_stats; struct i40e_rx_buffer* rx_bi; } ;

/* Variables and functions */

__attribute__((used)) static void i40e_reuse_rx_page(struct i40e_ring *rx_ring,
			       struct i40e_rx_buffer *old_buff)
{
	struct i40e_rx_buffer *new_buff;
	u16 nta = rx_ring->next_to_alloc;

	new_buff = &rx_ring->rx_bi[nta];

	/* update, and store next to alloc */
	nta++;
	rx_ring->next_to_alloc = (nta < rx_ring->count) ? nta : 0;

	/* transfer page from old buffer to new buffer */
	new_buff->dma		= old_buff->dma;
	new_buff->page		= old_buff->page;
	new_buff->page_offset	= old_buff->page_offset;
	new_buff->pagecnt_bias	= old_buff->pagecnt_bias;

	rx_ring->rx_stats.page_reuse_count++;

	/* clear contents of buffer_info */
	old_buff->page = NULL;
}
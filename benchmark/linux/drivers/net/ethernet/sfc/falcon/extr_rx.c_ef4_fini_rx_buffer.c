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
struct ef4_rx_queue {int /*<<< orphan*/  efx; } ;
struct ef4_rx_buffer {int flags; int /*<<< orphan*/ * page; } ;

/* Variables and functions */
 int EF4_RX_BUF_LAST_IN_PAGE ; 
 int /*<<< orphan*/  ef4_free_rx_buffers (struct ef4_rx_queue*,struct ef4_rx_buffer*,int) ; 
 int /*<<< orphan*/  ef4_unmap_rx_buffer (int /*<<< orphan*/ ,struct ef4_rx_buffer*) ; 
 int /*<<< orphan*/  put_page (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void ef4_fini_rx_buffer(struct ef4_rx_queue *rx_queue,
			       struct ef4_rx_buffer *rx_buf)
{
	/* Release the page reference we hold for the buffer. */
	if (rx_buf->page)
		put_page(rx_buf->page);

	/* If this is the last buffer in a page, unmap and free it. */
	if (rx_buf->flags & EF4_RX_BUF_LAST_IN_PAGE) {
		ef4_unmap_rx_buffer(rx_queue->efx, rx_buf);
		ef4_free_rx_buffers(rx_queue, rx_buf, 1);
	}
	rx_buf->page = NULL;
}
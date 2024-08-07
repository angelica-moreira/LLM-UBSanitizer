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
struct ag71xx_ring {scalar_t__ curr; int dirty; TYPE_2__* buf; int /*<<< orphan*/  order; } ;
struct ag71xx_desc {int /*<<< orphan*/  ctrl; } ;
struct ag71xx {int rx_buf_offset; int /*<<< orphan*/  ndev; struct ag71xx_ring rx_ring; } ;
struct TYPE_3__ {int /*<<< orphan*/  rx_buf; } ;
struct TYPE_4__ {TYPE_1__ rx; } ;

/* Variables and functions */
 int BIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DESC_EMPTY ; 
 int /*<<< orphan*/  ag71xx_fill_rx_buf (struct ag71xx*,TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 struct ag71xx_desc* ag71xx_ring_desc (struct ag71xx_ring*,unsigned int) ; 
 int /*<<< orphan*/  napi_alloc_frag ; 
 int /*<<< orphan*/  netif_dbg (struct ag71xx*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,unsigned int) ; 
 int /*<<< orphan*/  rx_status ; 
 int /*<<< orphan*/  wmb () ; 

__attribute__((used)) static int ag71xx_ring_rx_refill(struct ag71xx *ag)
{
	struct ag71xx_ring *ring = &ag->rx_ring;
	int ring_mask = BIT(ring->order) - 1;
	int offset = ag->rx_buf_offset;
	unsigned int count;

	count = 0;
	for (; ring->curr - ring->dirty > 0; ring->dirty++) {
		struct ag71xx_desc *desc;
		unsigned int i;

		i = ring->dirty & ring_mask;
		desc = ag71xx_ring_desc(ring, i);

		if (!ring->buf[i].rx.rx_buf &&
		    !ag71xx_fill_rx_buf(ag, &ring->buf[i], offset,
					napi_alloc_frag))
			break;

		desc->ctrl = DESC_EMPTY;
		count++;
	}

	/* flush descriptors */
	wmb();

	netif_dbg(ag, rx_status, ag->ndev, "%u rx descriptors refilled\n",
		  count);

	return count;
}
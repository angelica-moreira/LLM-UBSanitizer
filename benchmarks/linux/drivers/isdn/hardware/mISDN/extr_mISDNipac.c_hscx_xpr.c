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
struct TYPE_3__ {scalar_t__ tx_idx; int /*<<< orphan*/  Flags; TYPE_2__* tx_skb; } ;
struct hscx_hw {TYPE_1__ bch; } ;
struct TYPE_4__ {scalar_t__ len; } ;

/* Variables and functions */
 int /*<<< orphan*/  FLG_TX_EMPTY ; 
 int /*<<< orphan*/  dev_kfree_skb (TYPE_2__*) ; 
 scalar_t__ get_next_bframe (TYPE_1__*) ; 
 int /*<<< orphan*/  hscx_fill_fifo (struct hscx_hw*) ; 
 int /*<<< orphan*/  test_and_clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
hscx_xpr(struct hscx_hw *hx)
{
	if (hx->bch.tx_skb && hx->bch.tx_idx < hx->bch.tx_skb->len) {
		hscx_fill_fifo(hx);
	} else {
		dev_kfree_skb(hx->bch.tx_skb);
		if (get_next_bframe(&hx->bch)) {
			hscx_fill_fifo(hx);
			test_and_clear_bit(FLG_TX_EMPTY, &hx->bch.Flags);
		} else if (test_bit(FLG_TX_EMPTY, &hx->bch.Flags)) {
			hscx_fill_fifo(hx);
		}
	}
}
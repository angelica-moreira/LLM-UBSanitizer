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
struct sxgbe_tx_ctxt_desc {int own_bit; } ;

/* Variables and functions */

__attribute__((used)) static int sxgbe_tx_ctxt_desc_get_owner(struct sxgbe_tx_ctxt_desc *p)
{
	return p->own_bit;
}
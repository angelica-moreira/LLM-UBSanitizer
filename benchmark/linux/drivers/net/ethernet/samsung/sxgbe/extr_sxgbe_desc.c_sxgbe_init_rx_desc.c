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
struct TYPE_3__ {int own_bit; int int_on_com; } ;
struct TYPE_4__ {TYPE_1__ rx_rd_des23; } ;
struct sxgbe_rx_norm_desc {TYPE_2__ rdes23; } ;

/* Variables and functions */

__attribute__((used)) static void sxgbe_init_rx_desc(struct sxgbe_rx_norm_desc *p, int disable_rx_ic,
			       int mode, int end)
{
	p->rdes23.rx_rd_des23.own_bit = 1;
	if (disable_rx_ic)
		p->rdes23.rx_rd_des23.int_on_com = disable_rx_ic;
}
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
struct bna_rx_mod {int /*<<< orphan*/  (* stop_cbfn ) (int /*<<< orphan*/ *) ;TYPE_1__* bna; } ;
struct TYPE_2__ {int /*<<< orphan*/  enet; } ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
bna_rx_mod_cb_rx_stopped_all(void *arg)
{
	struct bna_rx_mod *rx_mod = (struct bna_rx_mod *)arg;

	if (rx_mod->stop_cbfn)
		rx_mod->stop_cbfn(&rx_mod->bna->enet);
	rx_mod->stop_cbfn = NULL;
}
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
struct bna_enet {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  bna_bfi_pause_set (struct bna_enet*) ; 

__attribute__((used)) static void
bna_enet_sm_pause_init_wait_entry(struct bna_enet *enet)
{
	bna_bfi_pause_set(enet);
}
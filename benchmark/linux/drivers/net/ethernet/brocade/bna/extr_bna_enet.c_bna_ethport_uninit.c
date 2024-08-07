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
struct bna_ethport {int /*<<< orphan*/ * bna; int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  BNA_ETHPORT_F_ADMIN_UP ; 
 int /*<<< orphan*/  BNA_ETHPORT_F_PORT_ENABLED ; 

__attribute__((used)) static void
bna_ethport_uninit(struct bna_ethport *ethport)
{
	ethport->flags &= ~BNA_ETHPORT_F_ADMIN_UP;
	ethport->flags &= ~BNA_ETHPORT_F_PORT_ENABLED;

	ethport->bna = NULL;
}
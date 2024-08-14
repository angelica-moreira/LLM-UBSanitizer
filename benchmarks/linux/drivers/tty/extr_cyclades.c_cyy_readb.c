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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
struct TYPE_3__ {scalar_t__ base_addr; } ;
struct TYPE_4__ {TYPE_1__ cyy; } ;
struct cyclades_port {TYPE_2__ u; struct cyclades_card* card; } ;
struct cyclades_card {int bus_index; } ;

/* Variables and functions */
 int /*<<< orphan*/  readb (scalar_t__) ; 

__attribute__((used)) static u8 cyy_readb(struct cyclades_port *port, u32 reg)
{
	struct cyclades_card *card = port->card;

	return readb(port->u.cyy.base_addr + (reg << card->bus_index));
}
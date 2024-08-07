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
struct TYPE_2__ {int /*<<< orphan*/  control; } ;
union xhci_trb {TYPE_1__ link; } ;

/* Variables and functions */
 int TRB_TYPE_LINK_LE32 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool trb_is_link(union xhci_trb *trb)
{
	return TRB_TYPE_LINK_LE32(trb->link.control);
}
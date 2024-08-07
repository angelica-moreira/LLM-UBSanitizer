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
typedef  scalar_t__ u16 ;
struct TYPE_3__ {int /*<<< orphan*/  dsr; } ;
struct TYPE_4__ {scalar_t__ line; TYPE_1__ icount; } ;
struct dz_port {TYPE_2__ port; } ;

/* Variables and functions */
 scalar_t__ DZ_MODEM ; 
 int /*<<< orphan*/  DZ_MSR ; 
 scalar_t__ dz_in (struct dz_port*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void check_modem_status(struct dz_port *dport)
{
	/*
	 * FIXME:
	 * 1. No status change interrupt; use a timer.
	 * 2. Handle the 3100/5000 as appropriate. --macro
	 */
	u16 status;

	/* If not the modem line just return.  */
	if (dport->port.line != DZ_MODEM)
		return;

	status = dz_in(dport, DZ_MSR);

	/* it's easy, since DSR2 is the only bit in the register */
	if (status)
		dport->port.icount.dsr++;
}
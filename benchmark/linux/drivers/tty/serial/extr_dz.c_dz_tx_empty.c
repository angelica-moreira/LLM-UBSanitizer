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
struct uart_port {int dummy; } ;
struct TYPE_2__ {int line; } ;
struct dz_port {TYPE_1__ port; } ;

/* Variables and functions */
 int /*<<< orphan*/  DZ_TCR ; 
 unsigned int TIOCSER_TEMT ; 
 unsigned short dz_in (struct dz_port*,int /*<<< orphan*/ ) ; 
 struct dz_port* to_dport (struct uart_port*) ; 

__attribute__((used)) static unsigned int dz_tx_empty(struct uart_port *uport)
{
	struct dz_port *dport = to_dport(uport);
	unsigned short tmp, mask = 1 << dport->port.line;

	tmp = dz_in(dport, DZ_TCR);
	tmp &= mask;

	return tmp ? 0 : TIOCSER_TEMT;
}
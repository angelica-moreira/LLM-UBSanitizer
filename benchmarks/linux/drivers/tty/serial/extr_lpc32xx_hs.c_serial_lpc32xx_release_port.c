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
struct uart_port {scalar_t__ iotype; int flags; scalar_t__ mapbase; int /*<<< orphan*/ * membase; } ;

/* Variables and functions */
 int /*<<< orphan*/  SZ_4K ; 
 int UPF_IOREMAP ; 
 scalar_t__ UPIO_MEM32 ; 
 int /*<<< orphan*/  iounmap (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  release_mem_region (scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void serial_lpc32xx_release_port(struct uart_port *port)
{
	if ((port->iotype == UPIO_MEM32) && (port->mapbase)) {
		if (port->flags & UPF_IOREMAP) {
			iounmap(port->membase);
			port->membase = NULL;
		}

		release_mem_region(port->mapbase, SZ_4K);
	}
}
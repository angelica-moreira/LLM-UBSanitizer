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
struct uart_port {int dummy; } ;

/* Variables and functions */
 unsigned int TIOCSER_TEMT ; 
 int /*<<< orphan*/  VT8500_URFIDX ; 
 int vt8500_read (struct uart_port*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned int vt8500_tx_empty(struct uart_port *port)
{
	return (vt8500_read(port, VT8500_URFIDX) & 0x1f) < 16 ?
						TIOCSER_TEMT : 0;
}
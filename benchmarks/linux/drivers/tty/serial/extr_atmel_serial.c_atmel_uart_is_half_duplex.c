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
struct TYPE_4__ {int flags; } ;
struct TYPE_3__ {int flags; } ;
struct uart_port {TYPE_2__ iso7816; TYPE_1__ rs485; } ;

/* Variables and functions */
 int SER_ISO7816_ENABLED ; 
 int SER_RS485_ENABLED ; 
 int SER_RS485_RX_DURING_TX ; 

__attribute__((used)) static inline int atmel_uart_is_half_duplex(struct uart_port *port)
{
	return ((port->rs485.flags & SER_RS485_ENABLED) &&
		!(port->rs485.flags & SER_RS485_RX_DURING_TX)) ||
		(port->iso7816.flags & SER_ISO7816_ENABLED);
}
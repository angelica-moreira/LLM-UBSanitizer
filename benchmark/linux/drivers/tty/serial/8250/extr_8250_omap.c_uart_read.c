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
typedef  int u32 ;
struct TYPE_2__ {int regshift; scalar_t__ membase; } ;
struct uart_8250_port {TYPE_1__ port; } ;

/* Variables and functions */
 int readl (scalar_t__) ; 

__attribute__((used)) static u32 uart_read(struct uart_8250_port *up, u32 reg)
{
	return readl(up->port.membase + (reg << up->port.regshift));
}
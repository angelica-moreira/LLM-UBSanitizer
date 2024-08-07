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
struct uart_port {int /*<<< orphan*/  dev; } ;
struct sccnxp_port {int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  CR_RX_DISABLE ; 
 int /*<<< orphan*/  SCCNXP_CR_REG ; 
 struct sccnxp_port* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sccnxp_port_write (struct uart_port*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void sccnxp_stop_rx(struct uart_port *port)
{
	struct sccnxp_port *s = dev_get_drvdata(port->dev);
	unsigned long flags;

	spin_lock_irqsave(&s->lock, flags);
	sccnxp_port_write(port, SCCNXP_CR_REG, CR_RX_DISABLE);
	spin_unlock_irqrestore(&s->lock, flags);
}
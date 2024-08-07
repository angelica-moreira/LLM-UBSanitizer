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
typedef  scalar_t__ u8 ;
struct uart_port {scalar_t__ iobase; int /*<<< orphan*/  dev; } ;
struct max310x_port {int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 struct max310x_port* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  regmap_write (int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 

__attribute__((used)) static void max310x_port_write(struct uart_port *port, u8 reg, u8 val)
{
	struct max310x_port *s = dev_get_drvdata(port->dev);

	regmap_write(s->regmap, port->iobase + reg, val);
}
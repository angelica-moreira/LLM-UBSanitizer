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
struct uart_port {int /*<<< orphan*/  irq; } ;
struct tegra_uart_port {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,struct tegra_uart_port*) ; 
 int /*<<< orphan*/  tegra_uart_hw_deinit (struct tegra_uart_port*) ; 
 struct tegra_uart_port* to_tegra_uport (struct uart_port*) ; 

__attribute__((used)) static void tegra_uart_shutdown(struct uart_port *u)
{
	struct tegra_uart_port *tup = to_tegra_uport(u);

	tegra_uart_hw_deinit(tup);
	free_irq(u->irq, tup);
}
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
struct sdio_uart_port {int index; int /*<<< orphan*/  xmit_fifo; int /*<<< orphan*/  write_lock; int /*<<< orphan*/  func_lock; } ;

/* Variables and functions */
 int EBUSY ; 
 int ENOMEM ; 
 int /*<<< orphan*/  FIFO_SIZE ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int UART_NR ; 
 scalar_t__ kfifo_alloc (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 struct sdio_uart_port** sdio_uart_table ; 
 int /*<<< orphan*/  sdio_uart_table_lock ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int sdio_uart_add_port(struct sdio_uart_port *port)
{
	int index, ret = -EBUSY;

	mutex_init(&port->func_lock);
	spin_lock_init(&port->write_lock);
	if (kfifo_alloc(&port->xmit_fifo, FIFO_SIZE, GFP_KERNEL))
		return -ENOMEM;

	spin_lock(&sdio_uart_table_lock);
	for (index = 0; index < UART_NR; index++) {
		if (!sdio_uart_table[index]) {
			port->index = index;
			sdio_uart_table[index] = port;
			ret = 0;
			break;
		}
	}
	spin_unlock(&sdio_uart_table_lock);

	return ret;
}
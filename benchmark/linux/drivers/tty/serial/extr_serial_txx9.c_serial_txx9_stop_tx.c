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
struct uart_txx9_port {int dummy; } ;
struct uart_port {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  TXX9_SIDICR ; 
 int /*<<< orphan*/  TXX9_SIDICR_TIE ; 
 int /*<<< orphan*/  sio_mask (struct uart_txx9_port*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct uart_txx9_port* to_uart_txx9_port (struct uart_port*) ; 

__attribute__((used)) static void serial_txx9_stop_tx(struct uart_port *port)
{
	struct uart_txx9_port *up = to_uart_txx9_port(port);
	sio_mask(up, TXX9_SIDICR, TXX9_SIDICR_TIE);
}
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
struct uart_8250_port {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  UART_DLL_EM ; 
 int /*<<< orphan*/  UART_DLM_EM ; 
 int /*<<< orphan*/  serial_out (struct uart_8250_port*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void serial8250_em_serial_dl_write(struct uart_8250_port *up, int value)
{
	serial_out(up, UART_DLL_EM, value & 0xff);
	serial_out(up, UART_DLM_EM, value >> 8 & 0xff);
}
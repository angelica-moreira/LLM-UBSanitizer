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
struct pic32_sport {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  PIC32_SET (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PIC32_UART_MODE ; 
 int PIC32_UART_MODE_ON ; 
 int /*<<< orphan*/  PIC32_UART_STA ; 
 int PIC32_UART_STA_URXEN ; 
 int PIC32_UART_STA_UTXEN ; 
 int /*<<< orphan*/  pic32_uart_writel (struct pic32_sport*,int /*<<< orphan*/ ,int) ; 
 struct pic32_sport* to_pic32_sport (struct uart_port*) ; 

__attribute__((used)) static void pic32_uart_en_and_unmask(struct uart_port *port)
{
	struct pic32_sport *sport = to_pic32_sport(port);

	pic32_uart_writel(sport, PIC32_SET(PIC32_UART_STA),
				PIC32_UART_STA_UTXEN | PIC32_UART_STA_URXEN);
	pic32_uart_writel(sport, PIC32_SET(PIC32_UART_MODE),
				PIC32_UART_MODE_ON);
}
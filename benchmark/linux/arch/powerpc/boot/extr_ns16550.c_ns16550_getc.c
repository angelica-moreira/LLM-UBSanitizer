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

/* Variables and functions */
 int UART_LSR ; 
 unsigned char UART_LSR_DR ; 
 unsigned char in_8 (scalar_t__) ; 
 scalar_t__ reg_base ; 
 int reg_shift ; 

__attribute__((used)) static unsigned char ns16550_getc(void)
{
	while ((in_8(reg_base + (UART_LSR << reg_shift)) & UART_LSR_DR) == 0);
	return in_8(reg_base);
}
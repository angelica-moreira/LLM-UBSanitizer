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
typedef  int /*<<< orphan*/  u8 ;
struct TYPE_2__ {scalar_t__ mmio_base; } ;

/* Variables and functions */
 int /*<<< orphan*/  out_8 (scalar_t__,int /*<<< orphan*/ ) ; 
 TYPE_1__ udbg_uart ; 
 unsigned int udbg_uart_stride ; 

__attribute__((used)) static void udbg_uart_out_mmio(unsigned int reg, u8 data)
{
	out_8(udbg_uart.mmio_base + (reg * udbg_uart_stride), data);
}
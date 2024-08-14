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
struct rtsx_pcr {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  RTS5260_REG_GPIO_CTL0 ; 
 int /*<<< orphan*/  RTS5260_REG_GPIO_MASK ; 
 int /*<<< orphan*/  RTS5260_REG_GPIO_ON ; 
 int rtsx_pci_write_register (struct rtsx_pcr*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int rts5260_turn_on_led(struct rtsx_pcr *pcr)
{
	return rtsx_pci_write_register(pcr, RTS5260_REG_GPIO_CTL0,
		RTS5260_REG_GPIO_MASK, RTS5260_REG_GPIO_ON);
}
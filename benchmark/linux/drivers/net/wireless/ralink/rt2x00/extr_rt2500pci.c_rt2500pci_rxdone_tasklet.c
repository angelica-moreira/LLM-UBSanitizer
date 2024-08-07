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
struct rt2x00_dev {int /*<<< orphan*/  flags; int /*<<< orphan*/  rxdone_tasklet; } ;

/* Variables and functions */
 int /*<<< orphan*/  CSR8_RXDONE ; 
 int /*<<< orphan*/  DEVICE_STATE_ENABLED_RADIO ; 
 int /*<<< orphan*/  rt2500pci_enable_interrupt (struct rt2x00_dev*,int /*<<< orphan*/ ) ; 
 scalar_t__ rt2x00mmio_rxdone (struct rt2x00_dev*) ; 
 int /*<<< orphan*/  tasklet_schedule (int /*<<< orphan*/ *) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void rt2500pci_rxdone_tasklet(unsigned long data)
{
	struct rt2x00_dev *rt2x00dev = (struct rt2x00_dev *)data;
	if (rt2x00mmio_rxdone(rt2x00dev))
		tasklet_schedule(&rt2x00dev->rxdone_tasklet);
	else if (test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
		rt2500pci_enable_interrupt(rt2x00dev, CSR8_RXDONE);
}
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
struct pci_dev {int dummy; } ;
struct bt8xxgpio {int /*<<< orphan*/  gpio; } ;

/* Variables and functions */
 int /*<<< orphan*/  BT848_GPIO_OUT_EN ; 
 int /*<<< orphan*/  BT848_INT_MASK ; 
 int /*<<< orphan*/  BT848_INT_STAT ; 
 int /*<<< orphan*/  bgwrite (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpiochip_remove (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pci_disable_device (struct pci_dev*) ; 
 struct bt8xxgpio* pci_get_drvdata (struct pci_dev*) ; 

__attribute__((used)) static void bt8xxgpio_remove(struct pci_dev *pdev)
{
	struct bt8xxgpio *bg = pci_get_drvdata(pdev);

	gpiochip_remove(&bg->gpio);

	bgwrite(0, BT848_INT_MASK);
	bgwrite(~0x0, BT848_INT_STAT);
	bgwrite(0x0, BT848_GPIO_OUT_EN);

	pci_disable_device(pdev);
}
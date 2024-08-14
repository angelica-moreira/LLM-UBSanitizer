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
struct vga_switcheroo_client_ops {int dummy; } ;
struct pci_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  VGA_SWITCHEROO_UNKNOWN_ID ; 
 int register_client (struct pci_dev*,struct vga_switcheroo_client_ops const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int) ; 
 struct pci_dev* vga_default_device () ; 

int vga_switcheroo_register_client(struct pci_dev *pdev,
				   const struct vga_switcheroo_client_ops *ops,
				   bool driver_power_control)
{
	return register_client(pdev, ops, VGA_SWITCHEROO_UNKNOWN_ID, NULL,
			       pdev == vga_default_device(),
			       driver_power_control);
}
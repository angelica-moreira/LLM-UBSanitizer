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
struct pci_device_id {int /*<<< orphan*/  driver_data; } ;
struct pci_dev {int dummy; } ;

/* Variables and functions */
 int comedi_pci_auto_config (struct pci_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  das08_pci_comedi_driver ; 

__attribute__((used)) static int das08_pci_probe(struct pci_dev *dev,
			   const struct pci_device_id *id)
{
	return comedi_pci_auto_config(dev, &das08_pci_comedi_driver,
				      id->driver_data);
}
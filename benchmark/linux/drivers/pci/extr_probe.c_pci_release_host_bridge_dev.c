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
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  devm_pci_release_host_bridge_dev (struct device*) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  to_pci_host_bridge (struct device*) ; 

__attribute__((used)) static void pci_release_host_bridge_dev(struct device *dev)
{
	devm_pci_release_host_bridge_dev(dev);
	kfree(to_pci_host_bridge(dev));
}
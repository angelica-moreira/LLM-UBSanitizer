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
struct kobject {int dummy; } ;
struct edac_pci_dev_attribute {int /*<<< orphan*/  value; int /*<<< orphan*/  (* store ) (int /*<<< orphan*/ ,char const*,size_t) ;} ;
struct attribute {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  EIO ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,char const*,size_t) ; 

__attribute__((used)) static ssize_t edac_pci_dev_store(struct kobject *kobj,
				struct attribute *attr, const char *buffer,
				size_t count)
{
	struct edac_pci_dev_attribute *edac_pci_dev;
	edac_pci_dev = (struct edac_pci_dev_attribute *)attr;

	if (edac_pci_dev->store)
		return edac_pci_dev->store(edac_pci_dev->value, buffer, count);
	return -EIO;
}
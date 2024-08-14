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
struct isci_remote_device {int dummy; } ;
struct isci_host {int /*<<< orphan*/  scic_lock; } ;
struct domain_device {int /*<<< orphan*/  lldd_dev; } ;

/* Variables and functions */
 int ENODEV ; 
 struct isci_host* dev_to_ihost (struct domain_device*) ; 
 struct isci_remote_device* isci_get_device (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  isci_put_device (struct isci_remote_device*) ; 
 int isci_reset_device (struct isci_host*,struct domain_device*,struct isci_remote_device*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

int isci_task_I_T_nexus_reset(struct domain_device *dev)
{
	struct isci_host *ihost = dev_to_ihost(dev);
	struct isci_remote_device *idev;
	unsigned long flags;
	int ret;

	spin_lock_irqsave(&ihost->scic_lock, flags);
	idev = isci_get_device(dev->lldd_dev);
	spin_unlock_irqrestore(&ihost->scic_lock, flags);

	if (!idev) {
		/* XXX: need to cleanup any ireqs targeting this
		 * domain_device
		 */
		ret = -ENODEV;
		goto out;
	}

	ret = isci_reset_device(ihost, dev, idev);
 out:
	isci_put_device(idev);
	return ret;
}
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
struct pci_bus {int dummy; } ;
struct device {int dummy; } ;
struct dca_provider {int /*<<< orphan*/  node; } ;
struct dca_domain {int /*<<< orphan*/  dca_providers; int /*<<< orphan*/  node; } ;

/* Variables and functions */
 int /*<<< orphan*/  DCA_PROVIDER_ADD ; 
 int ENODEV ; 
 int /*<<< orphan*/  blocking_notifier_call_chain (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct dca_domain* dca_allocate_domain (struct pci_bus*) ; 
 int /*<<< orphan*/  dca_domains ; 
 struct dca_domain* dca_get_domain (struct device*) ; 
 int /*<<< orphan*/  dca_lock ; 
 struct pci_bus* dca_pci_rc_from_dev (struct device*) ; 
 int /*<<< orphan*/  dca_provider_chain ; 
 scalar_t__ dca_providers_blocked ; 
 int dca_sysfs_add_provider (struct dca_provider*,struct device*) ; 
 int /*<<< orphan*/  dca_sysfs_remove_provider (struct dca_provider*) ; 
 int /*<<< orphan*/  kfree (struct dca_domain*) ; 
 int /*<<< orphan*/  list_add (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  raw_spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  unregister_dca_providers () ; 

int register_dca_provider(struct dca_provider *dca, struct device *dev)
{
	int err;
	unsigned long flags;
	struct dca_domain *domain, *newdomain = NULL;

	raw_spin_lock_irqsave(&dca_lock, flags);
	if (dca_providers_blocked) {
		raw_spin_unlock_irqrestore(&dca_lock, flags);
		return -ENODEV;
	}
	raw_spin_unlock_irqrestore(&dca_lock, flags);

	err = dca_sysfs_add_provider(dca, dev);
	if (err)
		return err;

	raw_spin_lock_irqsave(&dca_lock, flags);
	domain = dca_get_domain(dev);
	if (!domain) {
		struct pci_bus *rc;

		if (dca_providers_blocked) {
			raw_spin_unlock_irqrestore(&dca_lock, flags);
			dca_sysfs_remove_provider(dca);
			unregister_dca_providers();
			return -ENODEV;
		}

		raw_spin_unlock_irqrestore(&dca_lock, flags);
		rc = dca_pci_rc_from_dev(dev);
		newdomain = dca_allocate_domain(rc);
		if (!newdomain)
			return -ENODEV;
		raw_spin_lock_irqsave(&dca_lock, flags);
		/* Recheck, we might have raced after dropping the lock */
		domain = dca_get_domain(dev);
		if (!domain) {
			domain = newdomain;
			newdomain = NULL;
			list_add(&domain->node, &dca_domains);
		}
	}
	list_add(&dca->node, &domain->dca_providers);
	raw_spin_unlock_irqrestore(&dca_lock, flags);

	blocking_notifier_call_chain(&dca_provider_chain,
				     DCA_PROVIDER_ADD, NULL);
	kfree(newdomain);
	return 0;
}
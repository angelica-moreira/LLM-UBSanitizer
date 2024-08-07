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
struct pci_dev {int dummy; } ;
struct drm_device {scalar_t__ switch_power_state; } ;
struct device {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  hpd_work; } ;

/* Variables and functions */
 scalar_t__ DRM_SWITCH_POWER_DYNAMIC_OFF ; 
 scalar_t__ DRM_SWITCH_POWER_OFF ; 
 int /*<<< orphan*/  PCI_D0 ; 
 int nouveau_do_resume (struct drm_device*,int) ; 
 TYPE_1__* nouveau_drm (struct drm_device*) ; 
 int pci_enable_device (struct pci_dev*) ; 
 struct drm_device* pci_get_drvdata (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_restore_state (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_set_master (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_set_power_state (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  schedule_work (int /*<<< orphan*/ *) ; 
 struct pci_dev* to_pci_dev (struct device*) ; 

int
nouveau_pmops_resume(struct device *dev)
{
	struct pci_dev *pdev = to_pci_dev(dev);
	struct drm_device *drm_dev = pci_get_drvdata(pdev);
	int ret;

	if (drm_dev->switch_power_state == DRM_SWITCH_POWER_OFF ||
	    drm_dev->switch_power_state == DRM_SWITCH_POWER_DYNAMIC_OFF)
		return 0;

	pci_set_power_state(pdev, PCI_D0);
	pci_restore_state(pdev);
	ret = pci_enable_device(pdev);
	if (ret)
		return ret;
	pci_set_master(pdev);

	ret = nouveau_do_resume(drm_dev, false);

	/* Monitors may have been connected / disconnected during suspend */
	schedule_work(&nouveau_drm(drm_dev)->hpd_work);

	return ret;
}
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
struct pci_dev {scalar_t__ device; scalar_t__ subsystem_vendor; scalar_t__ subsystem_device; } ;
struct intel_quirk {scalar_t__ device; scalar_t__ subsystem_vendor; scalar_t__ subsystem_device; int /*<<< orphan*/  (* hook ) (struct drm_i915_private*) ;int /*<<< orphan*/ * dmi_id_list; } ;
struct TYPE_2__ {struct pci_dev* pdev; } ;
struct drm_i915_private {TYPE_1__ drm; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct intel_quirk*) ; 
 scalar_t__ PCI_ANY_ID ; 
 scalar_t__ dmi_check_system (int /*<<< orphan*/ ) ; 
 struct intel_quirk* intel_dmi_quirks ; 
 struct intel_quirk* intel_quirks ; 
 int /*<<< orphan*/  stub1 (struct drm_i915_private*) ; 
 int /*<<< orphan*/  stub2 (struct drm_i915_private*) ; 

void intel_init_quirks(struct drm_i915_private *i915)
{
	struct pci_dev *d = i915->drm.pdev;
	int i;

	for (i = 0; i < ARRAY_SIZE(intel_quirks); i++) {
		struct intel_quirk *q = &intel_quirks[i];

		if (d->device == q->device &&
		    (d->subsystem_vendor == q->subsystem_vendor ||
		     q->subsystem_vendor == PCI_ANY_ID) &&
		    (d->subsystem_device == q->subsystem_device ||
		     q->subsystem_device == PCI_ANY_ID))
			q->hook(i915);
	}
	for (i = 0; i < ARRAY_SIZE(intel_dmi_quirks); i++) {
		if (dmi_check_system(*intel_dmi_quirks[i].dmi_id_list) != 0)
			intel_dmi_quirks[i].hook(i915);
	}
}
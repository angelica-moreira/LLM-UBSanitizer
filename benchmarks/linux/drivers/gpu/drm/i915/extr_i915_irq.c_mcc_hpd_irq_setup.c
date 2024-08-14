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
typedef  int /*<<< orphan*/  u32 ;
struct drm_i915_private {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SDE_DDI_MASK_TGP ; 
 int /*<<< orphan*/  TGP_DDI_HPD_ENABLE_MASK ; 
 int /*<<< orphan*/  hpd_mcc ; 
 int /*<<< orphan*/  ibx_display_interrupt_update (struct drm_i915_private*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  icp_hpd_detection_setup (struct drm_i915_private*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  intel_hpd_enabled_irqs (struct drm_i915_private*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void mcc_hpd_irq_setup(struct drm_i915_private *dev_priv)
{
	u32 hotplug_irqs, enabled_irqs;

	hotplug_irqs = SDE_DDI_MASK_TGP;
	enabled_irqs = intel_hpd_enabled_irqs(dev_priv, hpd_mcc);

	ibx_display_interrupt_update(dev_priv, hotplug_irqs, enabled_irqs);

	icp_hpd_detection_setup(dev_priv, TGP_DDI_HPD_ENABLE_MASK, 0);
}
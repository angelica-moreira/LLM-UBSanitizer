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
typedef  int u32 ;
struct drm_i915_private {int* de_irq_mask; int /*<<< orphan*/  irq_lock; } ;
typedef  enum pipe { ____Placeholder_pipe } pipe ;

/* Variables and functions */
 int /*<<< orphan*/  GEN8_DE_PIPE_IMR (int) ; 
 int /*<<< orphan*/  I915_WRITE (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  POSTING_READ (int /*<<< orphan*/ ) ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  intel_irqs_enabled (struct drm_i915_private*) ; 
 int /*<<< orphan*/  lockdep_assert_held (int /*<<< orphan*/ *) ; 

void bdw_update_pipe_irq(struct drm_i915_private *dev_priv,
			 enum pipe pipe,
			 u32 interrupt_mask,
			 u32 enabled_irq_mask)
{
	u32 new_val;

	lockdep_assert_held(&dev_priv->irq_lock);

	WARN_ON(enabled_irq_mask & ~interrupt_mask);

	if (WARN_ON(!intel_irqs_enabled(dev_priv)))
		return;

	new_val = dev_priv->de_irq_mask[pipe];
	new_val &= ~interrupt_mask;
	new_val |= (~enabled_irq_mask & interrupt_mask);

	if (new_val != dev_priv->de_irq_mask[pipe]) {
		dev_priv->de_irq_mask[pipe] = new_val;
		I915_WRITE(GEN8_DE_PIPE_IMR(pipe), dev_priv->de_irq_mask[pipe]);
		POSTING_READ(GEN8_DE_PIPE_IMR(pipe));
	}
}
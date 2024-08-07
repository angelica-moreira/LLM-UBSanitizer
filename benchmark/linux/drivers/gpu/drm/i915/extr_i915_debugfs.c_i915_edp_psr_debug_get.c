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
typedef  int /*<<< orphan*/  u64 ;
struct TYPE_2__ {int /*<<< orphan*/  debug; } ;
struct drm_i915_private {TYPE_1__ psr; } ;

/* Variables and functions */
 int /*<<< orphan*/  CAN_PSR (struct drm_i915_private*) ; 
 int ENODEV ; 
 int /*<<< orphan*/  READ_ONCE (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
i915_edp_psr_debug_get(void *data, u64 *val)
{
	struct drm_i915_private *dev_priv = data;

	if (!CAN_PSR(dev_priv))
		return -ENODEV;

	*val = READ_ONCE(dev_priv->psr.debug);
	return 0;
}
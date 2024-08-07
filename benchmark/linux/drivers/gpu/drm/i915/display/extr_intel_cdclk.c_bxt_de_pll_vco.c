#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int bypass; int ref; } ;
struct TYPE_4__ {TYPE_1__ hw; } ;
struct drm_i915_private {TYPE_2__ cdclk; } ;

/* Variables and functions */
 int /*<<< orphan*/  MISSING_CASE (int) ; 

__attribute__((used)) static int bxt_de_pll_vco(struct drm_i915_private *dev_priv, int cdclk)
{
	int ratio;

	if (cdclk == dev_priv->cdclk.hw.bypass)
		return 0;

	switch (cdclk) {
	default:
		MISSING_CASE(cdclk);
		/* fall through */
	case 144000:
	case 288000:
	case 384000:
	case 576000:
		ratio = 60;
		break;
	case 624000:
		ratio = 65;
		break;
	}

	return dev_priv->cdclk.hw.ref * ratio;
}
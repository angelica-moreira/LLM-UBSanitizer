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
typedef  scalar_t__ u32 ;
struct drm_i915_private {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GEN10_NOA_WRITE_HIGH ; 
 int /*<<< orphan*/  OA_PERFCNT3_LO ; 
 int /*<<< orphan*/  OA_PERFCNT4_HI ; 
 scalar_t__ gen8_is_valid_mux_addr (struct drm_i915_private*,scalar_t__) ; 
 scalar_t__ i915_mmio_reg_offset (int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool gen10_is_valid_mux_addr(struct drm_i915_private *dev_priv, u32 addr)
{
	return gen8_is_valid_mux_addr(dev_priv, addr) ||
		addr == i915_mmio_reg_offset(GEN10_NOA_WRITE_HIGH) ||
		(addr >= i915_mmio_reg_offset(OA_PERFCNT3_LO) &&
		 addr <= i915_mmio_reg_offset(OA_PERFCNT4_HI));
}
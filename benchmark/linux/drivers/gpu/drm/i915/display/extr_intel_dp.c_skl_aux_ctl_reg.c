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
struct intel_dp {int dummy; } ;
struct intel_digital_port {int aux_ch; } ;
struct drm_i915_private {int dummy; } ;
typedef  int /*<<< orphan*/  i915_reg_t ;
typedef  enum aux_ch { ____Placeholder_aux_ch } aux_ch ;

/* Variables and functions */
#define  AUX_CH_A 133 
#define  AUX_CH_B 132 
#define  AUX_CH_C 131 
#define  AUX_CH_D 130 
#define  AUX_CH_E 129 
#define  AUX_CH_F 128 
 int /*<<< orphan*/  DP_AUX_CH_CTL (int const) ; 
 int /*<<< orphan*/  MISSING_CASE (int) ; 
 struct intel_digital_port* dp_to_dig_port (struct intel_dp*) ; 
 struct drm_i915_private* dp_to_i915 (struct intel_dp*) ; 

__attribute__((used)) static i915_reg_t skl_aux_ctl_reg(struct intel_dp *intel_dp)
{
	struct drm_i915_private *dev_priv = dp_to_i915(intel_dp);
	struct intel_digital_port *dig_port = dp_to_dig_port(intel_dp);
	enum aux_ch aux_ch = dig_port->aux_ch;

	switch (aux_ch) {
	case AUX_CH_A:
	case AUX_CH_B:
	case AUX_CH_C:
	case AUX_CH_D:
	case AUX_CH_E:
	case AUX_CH_F:
		return DP_AUX_CH_CTL(aux_ch);
	default:
		MISSING_CASE(aux_ch);
		return DP_AUX_CH_CTL(AUX_CH_A);
	}
}
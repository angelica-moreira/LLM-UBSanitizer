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
typedef  int u8 ;
struct TYPE_2__ {int /*<<< orphan*/  aux; } ;
struct intel_digital_port {TYPE_1__ dp; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  DP_AUX_HDCP_BSTATUS ; 
 int DP_BSTATUS_READY ; 
 int /*<<< orphan*/  DRM_DEBUG_KMS (char*,int) ; 
 int EIO ; 
 int drm_dp_dpcd_read (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*,int) ; 

__attribute__((used)) static
int intel_dp_hdcp_read_ksv_ready(struct intel_digital_port *intel_dig_port,
				 bool *ksv_ready)
{
	ssize_t ret;
	u8 bstatus;
	ret = drm_dp_dpcd_read(&intel_dig_port->dp.aux, DP_AUX_HDCP_BSTATUS,
			       &bstatus, 1);
	if (ret != 1) {
		DRM_DEBUG_KMS("Read bstatus from DP/AUX failed (%zd)\n", ret);
		return ret >= 0 ? -EIO : ret;
	}
	*ksv_ready = bstatus & DP_BSTATUS_READY;
	return 0;
}
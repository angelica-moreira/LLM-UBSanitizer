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
typedef  int /*<<< orphan*/  u8 ;
struct TYPE_2__ {int /*<<< orphan*/  aux; } ;
struct intel_digital_port {TYPE_1__ dp; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  DP_AUX_HDCP_BINFO ; 
 int /*<<< orphan*/  DRM_DEBUG_KMS (char*,int) ; 
 int DRM_HDCP_BSTATUS_LEN ; 
 int EIO ; 
 int drm_dp_dpcd_read (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int intel_dp_hdcp_read_bstatus(struct intel_digital_port *intel_dig_port,
				      u8 *bstatus)
{
	ssize_t ret;
	/*
	 * For some reason the HDMI and DP HDCP specs call this register
	 * definition by different names. In the HDMI spec, it's called BSTATUS,
	 * but in DP it's called BINFO.
	 */
	ret = drm_dp_dpcd_read(&intel_dig_port->dp.aux, DP_AUX_HDCP_BINFO,
			       bstatus, DRM_HDCP_BSTATUS_LEN);
	if (ret != DRM_HDCP_BSTATUS_LEN) {
		DRM_DEBUG_KMS("Read bstatus from DP/AUX failed (%zd)\n", ret);
		return ret >= 0 ? -EIO : ret;
	}
	return 0;
}
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

/* Variables and functions */
#define  WMFW_ADSP1_DM 135 
#define  WMFW_ADSP1_PM 134 
#define  WMFW_ADSP1_ZM 133 
#define  WMFW_ADSP2_XM 132 
#define  WMFW_ADSP2_YM 131 
#define  WMFW_HALO_PM_PACKED 130 
#define  WMFW_HALO_XM_PACKED 129 
#define  WMFW_HALO_YM_PACKED 128 

__attribute__((used)) static const char *wm_adsp_mem_region_name(unsigned int type)
{
	switch (type) {
	case WMFW_ADSP1_PM:
		return "PM";
	case WMFW_HALO_PM_PACKED:
		return "PM_PACKED";
	case WMFW_ADSP1_DM:
		return "DM";
	case WMFW_ADSP2_XM:
		return "XM";
	case WMFW_HALO_XM_PACKED:
		return "XM_PACKED";
	case WMFW_ADSP2_YM:
		return "YM";
	case WMFW_HALO_YM_PACKED:
		return "YM_PACKED";
	case WMFW_ADSP1_ZM:
		return "ZM";
	default:
		return NULL;
	}
}
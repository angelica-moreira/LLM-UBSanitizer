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
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  u32 ;

/* Variables and functions */
#define  DRM_FORMAT_BGRX8888 129 
#define  DRM_FORMAT_XRGB8888 128 
 int EINVAL ; 
 int /*<<< orphan*/  SUN4I_FRONTEND_OUTPUT_FMT_DATA_FMT_BGRX8888 ; 
 int /*<<< orphan*/  SUN4I_FRONTEND_OUTPUT_FMT_DATA_FMT_XRGB8888 ; 

__attribute__((used)) static int sun4i_frontend_drm_format_to_output_fmt(uint32_t fmt, u32 *val)
{
	switch (fmt) {
	case DRM_FORMAT_BGRX8888:
		*val = SUN4I_FRONTEND_OUTPUT_FMT_DATA_FMT_BGRX8888;
		return 0;

	case DRM_FORMAT_XRGB8888:
		*val = SUN4I_FRONTEND_OUTPUT_FMT_DATA_FMT_XRGB8888;
		return 0;

	default:
		return -EINVAL;
	}
}
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
struct drm_format_info {int* cpp; } ;

/* Variables and functions */
#define  DRM_FORMAT_VUY101010 130 
#define  DRM_FORMAT_YUV420_10BIT 129 
#define  DRM_FORMAT_YUV420_8BIT 128 
 struct drm_format_info* drm_format_info (int) ; 

int malidp_format_get_bpp(u32 fmt)
{
	const struct drm_format_info *info = drm_format_info(fmt);
	int bpp = info->cpp[0] * 8;

	if (bpp == 0) {
		switch (fmt) {
		case DRM_FORMAT_VUY101010:
			bpp = 30;
			break;
		case DRM_FORMAT_YUV420_10BIT:
			bpp = 15;
			break;
		case DRM_FORMAT_YUV420_8BIT:
			bpp = 12;
			break;
		default:
			bpp = 0;
		}
	}

	return bpp;
}
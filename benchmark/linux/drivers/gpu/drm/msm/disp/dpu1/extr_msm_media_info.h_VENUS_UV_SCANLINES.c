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
#define  COLOR_FMT_NV12 134 
#define  COLOR_FMT_NV12_BPP10_UBWC 133 
#define  COLOR_FMT_NV12_MVTB 132 
#define  COLOR_FMT_NV12_UBWC 131 
#define  COLOR_FMT_NV21 130 
#define  COLOR_FMT_P010 129 
#define  COLOR_FMT_P010_UBWC 128 
 unsigned int MSM_MEDIA_ALIGN (int,int) ; 

__attribute__((used)) static unsigned int VENUS_UV_SCANLINES(int color_fmt, int height)
{
	unsigned int sclines = 0;

	if (!height)
		return 0;

	switch (color_fmt) {
	case COLOR_FMT_NV21:
	case COLOR_FMT_NV12:
	case COLOR_FMT_NV12_MVTB:
	case COLOR_FMT_NV12_BPP10_UBWC:
	case COLOR_FMT_P010_UBWC:
	case COLOR_FMT_P010:
		sclines = MSM_MEDIA_ALIGN((height + 1) >> 1, 16);
		break;
	case COLOR_FMT_NV12_UBWC:
		sclines = MSM_MEDIA_ALIGN((height + 1) >> 1, 32);
		break;
	}

	return sclines;
}
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
typedef  enum ipu_color_space { ____Placeholder_ipu_color_space } ipu_color_space ;

/* Variables and functions */
 int IPUV3_COLORSPACE_RGB ; 
 int IPUV3_COLORSPACE_UNKNOWN ; 
 int IPUV3_COLORSPACE_YUV ; 
#define  V4L2_PIX_FMT_ABGR32 147 
#define  V4L2_PIX_FMT_ARGB32 146 
#define  V4L2_PIX_FMT_BGR24 145 
#define  V4L2_PIX_FMT_BGRA32 144 
#define  V4L2_PIX_FMT_BGRX32 143 
#define  V4L2_PIX_FMT_NV12 142 
#define  V4L2_PIX_FMT_NV16 141 
#define  V4L2_PIX_FMT_NV21 140 
#define  V4L2_PIX_FMT_NV61 139 
#define  V4L2_PIX_FMT_RGB24 138 
#define  V4L2_PIX_FMT_RGB565 137 
#define  V4L2_PIX_FMT_RGBA32 136 
#define  V4L2_PIX_FMT_RGBX32 135 
#define  V4L2_PIX_FMT_UYVY 134 
#define  V4L2_PIX_FMT_XBGR32 133 
#define  V4L2_PIX_FMT_XRGB32 132 
#define  V4L2_PIX_FMT_YUV420 131 
#define  V4L2_PIX_FMT_YUV422P 130 
#define  V4L2_PIX_FMT_YUYV 129 
#define  V4L2_PIX_FMT_YVU420 128 

enum ipu_color_space ipu_pixelformat_to_colorspace(u32 pixelformat)
{
	switch (pixelformat) {
	case V4L2_PIX_FMT_YUV420:
	case V4L2_PIX_FMT_YVU420:
	case V4L2_PIX_FMT_YUV422P:
	case V4L2_PIX_FMT_UYVY:
	case V4L2_PIX_FMT_YUYV:
	case V4L2_PIX_FMT_NV12:
	case V4L2_PIX_FMT_NV21:
	case V4L2_PIX_FMT_NV16:
	case V4L2_PIX_FMT_NV61:
		return IPUV3_COLORSPACE_YUV;
	case V4L2_PIX_FMT_RGB565:
	case V4L2_PIX_FMT_BGR24:
	case V4L2_PIX_FMT_RGB24:
	case V4L2_PIX_FMT_ABGR32:
	case V4L2_PIX_FMT_XBGR32:
	case V4L2_PIX_FMT_BGRA32:
	case V4L2_PIX_FMT_BGRX32:
	case V4L2_PIX_FMT_RGBA32:
	case V4L2_PIX_FMT_RGBX32:
	case V4L2_PIX_FMT_ARGB32:
	case V4L2_PIX_FMT_XRGB32:
		return IPUV3_COLORSPACE_RGB;
	default:
		return IPUV3_COLORSPACE_UNKNOWN;
	}
}
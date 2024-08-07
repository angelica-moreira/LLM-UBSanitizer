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

/* Variables and functions */
#define  V4L2_PIX_FMT_NV12 129 
#define  V4L2_PIX_FMT_NV21 128 

__attribute__((used)) static inline int frame_stride(u32 w, u32 fmt)
{
	switch (fmt) {
	case V4L2_PIX_FMT_NV12:
	case V4L2_PIX_FMT_NV21:
		return w;
	default:
		return 0;
	}
}
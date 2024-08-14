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
typedef  enum v4l2_buf_type { ____Placeholder_v4l2_buf_type } v4l2_buf_type ;

/* Variables and functions */
#define  V4L2_BUF_TYPE_VIDEO_CAPTURE 129 
#define  V4L2_BUF_TYPE_VIDEO_OUTPUT 128 

__attribute__((used)) static const char *type_name(enum v4l2_buf_type type)
{
	switch (type) {
	case V4L2_BUF_TYPE_VIDEO_OUTPUT:
		return "Output";
	case V4L2_BUF_TYPE_VIDEO_CAPTURE:
		return "Capture";
	default:
		return "Invalid";
	}
}
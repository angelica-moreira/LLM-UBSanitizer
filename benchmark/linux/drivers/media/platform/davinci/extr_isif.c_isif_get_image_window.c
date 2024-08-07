#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct v4l2_rect {int dummy; } ;
struct TYPE_5__ {struct v4l2_rect win; } ;
struct TYPE_4__ {struct v4l2_rect win; } ;
struct TYPE_6__ {scalar_t__ if_type; TYPE_2__ ycbcr; TYPE_1__ bayer; } ;

/* Variables and functions */
 scalar_t__ VPFE_RAW_BAYER ; 
 TYPE_3__ isif_cfg ; 

__attribute__((used)) static void isif_get_image_window(struct v4l2_rect *win)
{
	if (isif_cfg.if_type == VPFE_RAW_BAYER)
		*win = isif_cfg.bayer.win;
	else
		*win = isif_cfg.ycbcr.win;
}
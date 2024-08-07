#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct vpe_fmt {scalar_t__ fourcc; } ;
struct TYPE_3__ {scalar_t__ pixelformat; } ;
struct TYPE_4__ {TYPE_1__ pix; } ;
struct v4l2_format {TYPE_2__ fmt; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (struct vpe_fmt*) ; 
 struct vpe_fmt* vpe_formats ; 

__attribute__((used)) static struct vpe_fmt *find_format(struct v4l2_format *f)
{
	struct vpe_fmt *fmt;
	unsigned int k;

	for (k = 0; k < ARRAY_SIZE(vpe_formats); k++) {
		fmt = &vpe_formats[k];
		if (fmt->fourcc == f->fmt.pix.pixelformat)
			return fmt;
	}

	return NULL;
}
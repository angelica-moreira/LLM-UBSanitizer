#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct v4l2_fmtdesc {unsigned int index; int /*<<< orphan*/  pixelformat; } ;
struct TYPE_3__ {int types; int /*<<< orphan*/  fourcc; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (TYPE_1__*) ; 
 int EINVAL ; 
 TYPE_1__* jpu_formats ; 

__attribute__((used)) static int jpu_enum_fmt(struct v4l2_fmtdesc *f, u32 type)
{
	unsigned int i, num = 0;

	for (i = 0; i < ARRAY_SIZE(jpu_formats); ++i) {
		if (jpu_formats[i].types & type) {
			if (num == f->index)
				break;
			++num;
		}
	}

	if (i >= ARRAY_SIZE(jpu_formats))
		return -EINVAL;

	f->pixelformat = jpu_formats[i].fourcc;

	return 0;
}
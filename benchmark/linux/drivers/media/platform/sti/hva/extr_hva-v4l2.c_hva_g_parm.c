#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  denominator; int /*<<< orphan*/  numerator; } ;
struct TYPE_6__ {TYPE_1__ timeperframe; int /*<<< orphan*/  capability; } ;
struct TYPE_7__ {TYPE_2__ output; } ;
struct v4l2_streamparm {scalar_t__ type; TYPE_3__ parm; } ;
struct v4l2_fract {int /*<<< orphan*/  denominator; int /*<<< orphan*/  numerator; } ;
struct TYPE_8__ {struct v4l2_fract time_per_frame; } ;
struct hva_ctx {TYPE_4__ ctrls; } ;
struct file {int /*<<< orphan*/  private_data; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ V4L2_BUF_TYPE_VIDEO_OUTPUT ; 
 int /*<<< orphan*/  V4L2_CAP_TIMEPERFRAME ; 
 struct hva_ctx* fh_to_ctx (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int hva_g_parm(struct file *file, void *fh, struct v4l2_streamparm *sp)
{
	struct hva_ctx *ctx = fh_to_ctx(file->private_data);
	struct v4l2_fract *time_per_frame = &ctx->ctrls.time_per_frame;

	if (sp->type != V4L2_BUF_TYPE_VIDEO_OUTPUT)
		return -EINVAL;

	sp->parm.output.capability = V4L2_CAP_TIMEPERFRAME;
	sp->parm.output.timeperframe.numerator = time_per_frame->numerator;
	sp->parm.output.timeperframe.denominator =
		time_per_frame->denominator;

	return 0;
}
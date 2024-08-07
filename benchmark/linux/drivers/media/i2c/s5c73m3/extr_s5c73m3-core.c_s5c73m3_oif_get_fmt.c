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
typedef  int /*<<< orphan*/  u32 ;
struct v4l2_subdev_pad_config {int dummy; } ;
struct v4l2_subdev_format {scalar_t__ which; int pad; int /*<<< orphan*/  format; } ;
struct v4l2_subdev {int dummy; } ;
struct s5c73m3_frame_size {int dummy; } ;
struct s5c73m3 {int /*<<< orphan*/  lock; struct s5c73m3_frame_size** oif_pix_size; int /*<<< orphan*/  mbus_code; } ;

/* Variables and functions */
 int EINVAL ; 
#define  OIF_ISP_PAD 130 
#define  OIF_JPEG_PAD 129 
#define  OIF_SOURCE_PAD 128 
 size_t RES_ISP ; 
 size_t RES_JPEG ; 
 int /*<<< orphan*/  S5C73M3_ISP_FMT ; 
 int /*<<< orphan*/  S5C73M3_JPEG_FMT ; 
 scalar_t__ V4L2_SUBDEV_FORMAT_TRY ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct s5c73m3* oif_sd_to_s5c73m3 (struct v4l2_subdev*) ; 
 int /*<<< orphan*/  s5c73m3_fill_mbus_fmt (int /*<<< orphan*/ *,struct s5c73m3_frame_size const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * v4l2_subdev_get_try_format (struct v4l2_subdev*,struct v4l2_subdev_pad_config*,int) ; 

__attribute__((used)) static int s5c73m3_oif_get_fmt(struct v4l2_subdev *sd,
			   struct v4l2_subdev_pad_config *cfg,
			   struct v4l2_subdev_format *fmt)
{
	struct s5c73m3 *state = oif_sd_to_s5c73m3(sd);
	const struct s5c73m3_frame_size *fs;
	u32 code;

	if (fmt->which == V4L2_SUBDEV_FORMAT_TRY) {
		fmt->format = *v4l2_subdev_get_try_format(sd, cfg, fmt->pad);
		return 0;
	}

	mutex_lock(&state->lock);

	switch (fmt->pad) {
	case OIF_ISP_PAD:
		code = S5C73M3_ISP_FMT;
		fs = state->oif_pix_size[RES_ISP];
		break;
	case OIF_JPEG_PAD:
		code = S5C73M3_JPEG_FMT;
		fs = state->oif_pix_size[RES_JPEG];
		break;
	case OIF_SOURCE_PAD:
		code = state->mbus_code;
		fs = state->oif_pix_size[RES_ISP];
		break;
	default:
		mutex_unlock(&state->lock);
		return -EINVAL;
	}
	s5c73m3_fill_mbus_fmt(&fmt->format, fs, code);

	mutex_unlock(&state->lock);
	return 0;
}
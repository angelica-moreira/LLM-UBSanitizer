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
struct v4l2_device {int dummy; } ;
struct iss_csi2_device {int /*<<< orphan*/  video_out; int /*<<< orphan*/  subdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  omap4iss_csi2_unregister_entities (struct iss_csi2_device*) ; 
 int omap4iss_video_register (int /*<<< orphan*/ *,struct v4l2_device*) ; 
 int v4l2_device_register_subdev (struct v4l2_device*,int /*<<< orphan*/ *) ; 

int omap4iss_csi2_register_entities(struct iss_csi2_device *csi2,
				    struct v4l2_device *vdev)
{
	int ret;

	/* Register the subdev and video nodes. */
	ret = v4l2_device_register_subdev(vdev, &csi2->subdev);
	if (ret < 0)
		goto error;

	ret = omap4iss_video_register(&csi2->video_out, vdev);
	if (ret < 0)
		goto error;

	return 0;

error:
	omap4iss_csi2_unregister_entities(csi2);
	return ret;
}
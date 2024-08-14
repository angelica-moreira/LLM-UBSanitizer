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
struct v4l2_jpegcompression {int jpeg_markers; int /*<<< orphan*/  quality; } ;
struct sd {scalar_t__ bridge; int /*<<< orphan*/  jpegqual; } ;
struct gspca_dev {int dummy; } ;

/* Variables and functions */
 scalar_t__ BRIDGE_W9968CF ; 
 int ENOTTY ; 
 int V4L2_JPEG_MARKER_DHT ; 
 int V4L2_JPEG_MARKER_DQT ; 
 int V4L2_JPEG_MARKER_DRI ; 
 int /*<<< orphan*/  memset (struct v4l2_jpegcompression*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  v4l2_ctrl_g_ctrl (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int sd_get_jcomp(struct gspca_dev *gspca_dev,
			struct v4l2_jpegcompression *jcomp)
{
	struct sd *sd = (struct sd *) gspca_dev;

	if (sd->bridge != BRIDGE_W9968CF)
		return -ENOTTY;

	memset(jcomp, 0, sizeof *jcomp);
	jcomp->quality = v4l2_ctrl_g_ctrl(sd->jpegqual);
	jcomp->jpeg_markers = V4L2_JPEG_MARKER_DHT | V4L2_JPEG_MARKER_DQT |
			      V4L2_JPEG_MARKER_DRI;
	return 0;
}
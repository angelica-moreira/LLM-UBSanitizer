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
typedef  int /*<<< orphan*/  v4l2_std_id ;
struct vpbe_layer {TYPE_1__* disp_dev; } ;
struct TYPE_4__ {int timings_type; int /*<<< orphan*/  std_id; } ;
struct vpbe_device {TYPE_2__ current_timings; int /*<<< orphan*/  v4l2_dev; } ;
struct file {int dummy; } ;
struct TYPE_3__ {struct vpbe_device* vpbe_dev; } ;

/* Variables and functions */
 int EINVAL ; 
 int VPBE_ENC_STD ; 
 int /*<<< orphan*/  debug ; 
 int /*<<< orphan*/  v4l2_dbg (int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,char*) ; 
 struct vpbe_layer* video_drvdata (struct file*) ; 

__attribute__((used)) static int vpbe_display_g_std(struct file *file, void *priv,
				v4l2_std_id *std_id)
{
	struct vpbe_layer *layer = video_drvdata(file);
	struct vpbe_device *vpbe_dev = layer->disp_dev->vpbe_dev;

	v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev,	"VIDIOC_G_STD\n");

	/* Get the standard from the current encoder */
	if (vpbe_dev->current_timings.timings_type & VPBE_ENC_STD) {
		*std_id = vpbe_dev->current_timings.std_id;
		return 0;
	}

	return -EINVAL;
}
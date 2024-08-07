#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct platform_device {int dummy; } ;
struct channel_obj {int /*<<< orphan*/  video_dev; } ;
struct TYPE_2__ {struct channel_obj** dev; struct channel_obj* sd; int /*<<< orphan*/  v4l2_dev; int /*<<< orphan*/  notifier; } ;

/* Variables and functions */
 int VPIF_CAPTURE_MAX_DEVICES ; 
 int /*<<< orphan*/  kfree (struct channel_obj*) ; 
 int /*<<< orphan*/  v4l2_async_notifier_cleanup (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  v4l2_async_notifier_unregister (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  v4l2_device_unregister (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  video_unregister_device (int /*<<< orphan*/ *) ; 
 TYPE_1__ vpif_obj ; 

__attribute__((used)) static int vpif_remove(struct platform_device *device)
{
	struct channel_obj *ch;
	int i;

	v4l2_async_notifier_unregister(&vpif_obj.notifier);
	v4l2_async_notifier_cleanup(&vpif_obj.notifier);
	v4l2_device_unregister(&vpif_obj.v4l2_dev);

	kfree(vpif_obj.sd);
	/* un-register device */
	for (i = 0; i < VPIF_CAPTURE_MAX_DEVICES; i++) {
		/* Get the pointer to the channel object */
		ch = vpif_obj.dev[i];
		/* Unregister video device */
		video_unregister_device(&ch->video_dev);
		kfree(vpif_obj.dev[i]);
	}
	return 0;
}
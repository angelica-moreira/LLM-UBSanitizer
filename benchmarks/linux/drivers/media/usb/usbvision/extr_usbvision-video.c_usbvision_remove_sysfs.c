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
struct video_device {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  dev_attr_bridge ; 
 int /*<<< orphan*/  dev_attr_brightness ; 
 int /*<<< orphan*/  dev_attr_compression ; 
 int /*<<< orphan*/  dev_attr_contrast ; 
 int /*<<< orphan*/  dev_attr_hue ; 
 int /*<<< orphan*/  dev_attr_model ; 
 int /*<<< orphan*/  dev_attr_saturation ; 
 int /*<<< orphan*/  dev_attr_streaming ; 
 int /*<<< orphan*/  dev_attr_version ; 
 int /*<<< orphan*/  device_remove_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void usbvision_remove_sysfs(struct video_device *vdev)
{
	if (vdev) {
		device_remove_file(&vdev->dev, &dev_attr_version);
		device_remove_file(&vdev->dev, &dev_attr_model);
		device_remove_file(&vdev->dev, &dev_attr_hue);
		device_remove_file(&vdev->dev, &dev_attr_contrast);
		device_remove_file(&vdev->dev, &dev_attr_brightness);
		device_remove_file(&vdev->dev, &dev_attr_saturation);
		device_remove_file(&vdev->dev, &dev_attr_streaming);
		device_remove_file(&vdev->dev, &dev_attr_compression);
		device_remove_file(&vdev->dev, &dev_attr_bridge);
	}
}
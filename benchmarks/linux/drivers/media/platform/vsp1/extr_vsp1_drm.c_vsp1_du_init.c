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
struct vsp1_device {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int EPROBE_DEFER ; 
 struct vsp1_device* dev_get_drvdata (struct device*) ; 

int vsp1_du_init(struct device *dev)
{
	struct vsp1_device *vsp1 = dev_get_drvdata(dev);

	if (!vsp1)
		return -EPROBE_DEFER;

	return 0;
}
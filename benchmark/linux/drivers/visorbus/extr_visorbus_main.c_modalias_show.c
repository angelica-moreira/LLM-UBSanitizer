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
struct visor_device {int /*<<< orphan*/  visorchannel; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;
typedef  int /*<<< orphan*/  guid_t ;

/* Variables and functions */
 int /*<<< orphan*/  sprintf (char*,char*,int /*<<< orphan*/  const*) ; 
 struct visor_device* to_visor_device (struct device*) ; 
 int /*<<< orphan*/ * visorchannel_get_guid (int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t modalias_show(struct device *dev, struct device_attribute *attr,
			     char *buf)
{
	struct visor_device *vdev;
	const guid_t *guid;

	vdev = to_visor_device(dev);
	guid = visorchannel_get_guid(vdev->visorchannel);
	return sprintf(buf, "visorbus:%pUl\n", guid);
}
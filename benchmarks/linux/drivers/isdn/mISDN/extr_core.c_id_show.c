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
struct mISDNdevice {int id; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  ENODEV ; 
 struct mISDNdevice* dev_to_mISDN (struct device*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 

__attribute__((used)) static ssize_t id_show(struct device *dev,
		       struct device_attribute *attr, char *buf)
{
	struct mISDNdevice *mdev = dev_to_mISDN(dev);

	if (!mdev)
		return -ENODEV;
	return sprintf(buf, "%d\n", mdev->id);
}
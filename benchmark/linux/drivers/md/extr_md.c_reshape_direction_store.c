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
struct mddev {int reshape_backwards; scalar_t__ major_version; scalar_t__ persistent; scalar_t__ delta_disks; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
 int EBUSY ; 
 size_t EINVAL ; 
 scalar_t__ cmd_match (char const*,char*) ; 
 int mddev_lock (struct mddev*) ; 
 int /*<<< orphan*/  mddev_unlock (struct mddev*) ; 

__attribute__((used)) static ssize_t
reshape_direction_store(struct mddev *mddev, const char *buf, size_t len)
{
	int backwards = 0;
	int err;

	if (cmd_match(buf, "forwards"))
		backwards = 0;
	else if (cmd_match(buf, "backwards"))
		backwards = 1;
	else
		return -EINVAL;
	if (mddev->reshape_backwards == backwards)
		return len;

	err = mddev_lock(mddev);
	if (err)
		return err;
	/* check if we are allowed to change */
	if (mddev->delta_disks)
		err = -EBUSY;
	else if (mddev->persistent &&
	    mddev->major_version == 0)
		err =  -EINVAL;
	else
		mddev->reshape_backwards = backwards;
	mddev_unlock(mddev);
	return err ?: len;
}
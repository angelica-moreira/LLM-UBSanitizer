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
struct r5conf {int dummy; } ;
struct mddev {struct r5conf* private; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 size_t PAGE_SIZE ; 
 scalar_t__ kstrtoul (char const*,int,unsigned long*) ; 
 int mddev_lock (struct mddev*) ; 
 int /*<<< orphan*/  mddev_unlock (struct mddev*) ; 
 int raid5_set_cache_size (struct mddev*,unsigned long) ; 

__attribute__((used)) static ssize_t
raid5_store_stripe_cache_size(struct mddev *mddev, const char *page, size_t len)
{
	struct r5conf *conf;
	unsigned long new;
	int err;

	if (len >= PAGE_SIZE)
		return -EINVAL;
	if (kstrtoul(page, 10, &new))
		return -EINVAL;
	err = mddev_lock(mddev);
	if (err)
		return err;
	conf = mddev->private;
	if (!conf)
		err = -ENODEV;
	else
		err = raid5_set_cache_size(mddev, new);
	mddev_unlock(mddev);

	return err ?: len;
}
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
struct mddev {unsigned long long suspend_hi; int /*<<< orphan*/ * pers; } ;
typedef  int ssize_t ;
typedef  unsigned long long sector_t ;

/* Variables and functions */
 int EINVAL ; 
 int kstrtoull (char const*,int,unsigned long long*) ; 
 int mddev_lock (struct mddev*) ; 
 int /*<<< orphan*/  mddev_resume (struct mddev*) ; 
 int /*<<< orphan*/  mddev_suspend (struct mddev*) ; 
 int /*<<< orphan*/  mddev_unlock (struct mddev*) ; 

__attribute__((used)) static ssize_t
suspend_hi_store(struct mddev *mddev, const char *buf, size_t len)
{
	unsigned long long new;
	int err;

	err = kstrtoull(buf, 10, &new);
	if (err < 0)
		return err;
	if (new != (sector_t)new)
		return -EINVAL;

	err = mddev_lock(mddev);
	if (err)
		return err;
	err = -EINVAL;
	if (mddev->pers == NULL)
		goto unlock;

	mddev_suspend(mddev);
	mddev->suspend_hi = new;
	mddev_resume(mddev);

	err = 0;
unlock:
	mddev_unlock(mddev);
	return err ?: len;
}
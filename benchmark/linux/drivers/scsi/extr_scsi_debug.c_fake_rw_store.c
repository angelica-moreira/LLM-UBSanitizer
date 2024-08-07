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
struct device_driver {int dummy; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
 size_t EINVAL ; 
 size_t ENOMEM ; 
 int /*<<< orphan*/ * fake_storep ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 scalar_t__ sdebug_dev_size_mb ; 
 int sdebug_fake_rw ; 
 int sscanf (char const*,char*,int*) ; 
 int /*<<< orphan*/ * vzalloc (unsigned long) ; 

__attribute__((used)) static ssize_t fake_rw_store(struct device_driver *ddp, const char *buf,
			     size_t count)
{
	int n;

	if ((count > 0) && (1 == sscanf(buf, "%d", &n)) && (n >= 0)) {
		n = (n > 0);
		sdebug_fake_rw = (sdebug_fake_rw > 0);
		if (sdebug_fake_rw != n) {
			if ((0 == n) && (NULL == fake_storep)) {
				unsigned long sz =
					(unsigned long)sdebug_dev_size_mb *
					1048576;

				fake_storep = vzalloc(sz);
				if (NULL == fake_storep) {
					pr_err("out of memory, 9\n");
					return -ENOMEM;
				}
			}
			sdebug_fake_rw = n;
		}
		return count;
	}
	return -EINVAL;
}
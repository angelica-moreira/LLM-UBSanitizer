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
struct b43legacy_wldev {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  b43legacy_controller_restart (struct b43legacy_wldev*,char*) ; 

__attribute__((used)) static int restart_write_file(struct b43legacy_wldev *dev, const char *buf, size_t count)
{
	int err = 0;

	if (count > 0 && buf[0] == '1') {
		b43legacy_controller_restart(dev, "manually restarted");
	} else
		err = -EINVAL;

	return err;
}
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
typedef  int /*<<< orphan*/  u64 ;
struct b43legacy_wldev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  b43legacy_time_lock (struct b43legacy_wldev*) ; 
 int /*<<< orphan*/  b43legacy_time_unlock (struct b43legacy_wldev*) ; 
 int /*<<< orphan*/  b43legacy_tsf_write_locked (struct b43legacy_wldev*,int /*<<< orphan*/ ) ; 

void b43legacy_tsf_write(struct b43legacy_wldev *dev, u64 tsf)
{
	b43legacy_time_lock(dev);
	b43legacy_tsf_write_locked(dev, tsf);
	b43legacy_time_unlock(dev);
}
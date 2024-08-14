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
struct ip6_flowlabel {unsigned long lastuse; unsigned long linger; unsigned long expires; } ;

/* Variables and functions */
 int EPERM ; 
 unsigned long check_linger (unsigned long) ; 
 int /*<<< orphan*/  ip6_fl_lock ; 
 unsigned long jiffies ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 
 scalar_t__ time_before (unsigned long,unsigned long) ; 

__attribute__((used)) static int fl6_renew(struct ip6_flowlabel *fl, unsigned long linger, unsigned long expires)
{
	linger = check_linger(linger);
	if (!linger)
		return -EPERM;
	expires = check_linger(expires);
	if (!expires)
		return -EPERM;

	spin_lock_bh(&ip6_fl_lock);
	fl->lastuse = jiffies;
	if (time_before(fl->linger, linger))
		fl->linger = linger;
	if (time_before(expires, fl->linger))
		expires = fl->linger;
	if (time_before(fl->expires, fl->lastuse + expires))
		fl->expires = fl->lastuse + expires;
	spin_unlock_bh(&ip6_fl_lock);

	return 0;
}
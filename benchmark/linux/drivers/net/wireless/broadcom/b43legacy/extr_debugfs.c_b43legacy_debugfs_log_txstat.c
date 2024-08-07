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
struct b43legacy_wldev {struct b43legacy_dfsentry* dfsentry; } ;
struct b43legacy_txstatus_log {int end; int /*<<< orphan*/  lock; struct b43legacy_txstatus* log; } ;
struct b43legacy_txstatus {int dummy; } ;
struct b43legacy_dfsentry {struct b43legacy_txstatus_log txstatlog; } ;

/* Variables and functions */
 int B43legacy_NR_LOGGED_TXSTATUS ; 
 int /*<<< orphan*/  B43legacy_WARN_ON (int) ; 
 int /*<<< orphan*/  irqs_disabled () ; 
 int /*<<< orphan*/  memcpy (struct b43legacy_txstatus*,struct b43legacy_txstatus const*,int) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

void b43legacy_debugfs_log_txstat(struct b43legacy_wldev *dev,
			    const struct b43legacy_txstatus *status)
{
	struct b43legacy_dfsentry *e = dev->dfsentry;
	struct b43legacy_txstatus_log *log;
	struct b43legacy_txstatus *cur;
	int i;

	if (!e)
		return;
	log = &e->txstatlog;
	B43legacy_WARN_ON(!irqs_disabled());
	spin_lock(&log->lock);
	i = log->end + 1;
	if (i == B43legacy_NR_LOGGED_TXSTATUS)
		i = 0;
	log->end = i;
	cur = &(log->log[i]);
	memcpy(cur, status, sizeof(*cur));
	spin_unlock(&log->lock);
}
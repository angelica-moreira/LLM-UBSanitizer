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

/* Variables and functions */
 int /*<<< orphan*/  FYI ; 
 int /*<<< orphan*/  GlobalCurrentXid ; 
 int GlobalMaxActiveXid ; 
 int /*<<< orphan*/  GlobalMid_Lock ; 
 int GlobalTotalActiveXid ; 
 int /*<<< orphan*/  cifs_dbg (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

unsigned int
_get_xid(void)
{
	unsigned int xid;

	spin_lock(&GlobalMid_Lock);
	GlobalTotalActiveXid++;

	/* keep high water mark for number of simultaneous ops in filesystem */
	if (GlobalTotalActiveXid > GlobalMaxActiveXid)
		GlobalMaxActiveXid = GlobalTotalActiveXid;
	if (GlobalTotalActiveXid > 65000)
		cifs_dbg(FYI, "warning: more than 65000 requests active\n");
	xid = GlobalCurrentXid++;
	spin_unlock(&GlobalMid_Lock);
	return xid;
}
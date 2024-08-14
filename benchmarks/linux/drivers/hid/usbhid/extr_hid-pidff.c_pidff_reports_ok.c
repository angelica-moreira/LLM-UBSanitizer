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
struct pidff_device {int /*<<< orphan*/  hid; int /*<<< orphan*/ * reports; } ;

/* Variables and functions */
 int PID_REQUIRED_REPORTS ; 
 int /*<<< orphan*/  hid_dbg (int /*<<< orphan*/ ,char*,int) ; 

__attribute__((used)) static int pidff_reports_ok(struct pidff_device *pidff)
{
	int i;

	for (i = 0; i <= PID_REQUIRED_REPORTS; i++) {
		if (!pidff->reports[i]) {
			hid_dbg(pidff->hid, "%d missing\n", i);
			return 0;
		}
	}

	return 1;
}
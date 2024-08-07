#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  wReportDescLength; } ;
struct gb_hid {int /*<<< orphan*/  bundle; TYPE_1__ hdesc; int /*<<< orphan*/  connection; } ;

/* Variables and functions */
 int /*<<< orphan*/  GB_HID_TYPE_GET_REPORT_DESC ; 
 int gb_operation_sync (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int gb_pm_runtime_get_sync (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gb_pm_runtime_put_autosuspend (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  le16_to_cpu (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int gb_hid_get_report_desc(struct gb_hid *ghid, char *rdesc)
{
	int ret;

	ret = gb_pm_runtime_get_sync(ghid->bundle);
	if (ret)
		return ret;

	ret = gb_operation_sync(ghid->connection, GB_HID_TYPE_GET_REPORT_DESC,
				NULL, 0, rdesc,
				le16_to_cpu(ghid->hdesc.wReportDescLength));

	gb_pm_runtime_put_autosuspend(ghid->bundle);

	return ret;
}
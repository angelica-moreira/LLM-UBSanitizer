#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct scsi_qla_host {TYPE_2__* pdev; int /*<<< orphan*/  host_no; } ;
typedef  int /*<<< orphan*/  event_string ;
struct TYPE_3__ {int /*<<< orphan*/  kobj; } ;
struct TYPE_4__ {TYPE_1__ dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  KOBJ_CHANGE ; 
#define  QL4_UEVENT_CODE_FW_DUMP 128 
 int /*<<< orphan*/  kobject_uevent_env (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char**) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void qla4_8xxx_uevent_emit(struct scsi_qla_host *ha, u32 code)
{
	char event_string[40];
	char *envp[] = { event_string, NULL };

	switch (code) {
	case QL4_UEVENT_CODE_FW_DUMP:
		snprintf(event_string, sizeof(event_string), "FW_DUMP=%ld",
			 ha->host_no);
		break;
	default:
		/*do nothing*/
		break;
	}

	kobject_uevent_env(&(&ha->pdev->dev)->kobj, KOBJ_CHANGE, envp);
}
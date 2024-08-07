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
struct asus_wmi {int fnlock_locked; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASUS_WMI_DEVID_FNLOCK ; 
 int /*<<< orphan*/  asus_wmi_set_devstate (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void asus_wmi_fnlock_update(struct asus_wmi *asus)
{
	int mode = asus->fnlock_locked;

	asus_wmi_set_devstate(ASUS_WMI_DEVID_FNLOCK, mode, NULL);
}
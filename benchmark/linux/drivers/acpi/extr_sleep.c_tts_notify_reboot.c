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
struct notifier_block {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_STATE_S5 ; 
 int NOTIFY_DONE ; 
 int /*<<< orphan*/  acpi_sleep_tts_switch (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int tts_notify_reboot(struct notifier_block *this,
			unsigned long code, void *x)
{
	acpi_sleep_tts_switch(ACPI_STATE_S5);
	return NOTIFY_DONE;
}
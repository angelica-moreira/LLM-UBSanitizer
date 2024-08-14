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
struct sev_data_activate {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SEV_CMD_ACTIVATE ; 
 int sev_do_cmd (int /*<<< orphan*/ ,struct sev_data_activate*,int*) ; 

int sev_guest_activate(struct sev_data_activate *data, int *error)
{
	return sev_do_cmd(SEV_CMD_ACTIVATE, data, error);
}
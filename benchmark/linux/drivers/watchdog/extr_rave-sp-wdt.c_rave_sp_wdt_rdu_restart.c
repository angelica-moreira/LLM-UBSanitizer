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
typedef  int u8 ;
struct watchdog_device {int dummy; } ;
typedef  int /*<<< orphan*/  cmd ;

/* Variables and functions */
 int RAVE_SP_CMD_RESET ; 
 int RAVE_SP_RESET_BYTE ; 
 int RAVE_SP_RESET_REASON_NORMAL ; 
 int rave_sp_wdt_exec (struct watchdog_device*,int*,int) ; 

__attribute__((used)) static int rave_sp_wdt_rdu_restart(struct watchdog_device *wdd)
{
	u8 cmd[] = {
		[0] = RAVE_SP_CMD_RESET,
		[1] = 0,
		[2] = RAVE_SP_RESET_BYTE,
		[3] = RAVE_SP_RESET_REASON_NORMAL
	};

	return rave_sp_wdt_exec(wdd, cmd, sizeof(cmd));
}
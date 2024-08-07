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
typedef  int /*<<< orphan*/  u8 ;
struct psmouse {int /*<<< orphan*/  ps2dev; } ;

/* Variables and functions */
 int PSMOUSE_CMD_POLL ; 
 int ps2_command (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int ps2_sliced_command (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ps2pp_cmd(struct psmouse *psmouse, u8 *param, u8 command)
{
	int error;

	error = ps2_sliced_command(&psmouse->ps2dev, command);
	if (error)
		return error;

	error = ps2_command(&psmouse->ps2dev, param, PSMOUSE_CMD_POLL | 0x0300);
	if (error)
		return error;

	return 0;
}
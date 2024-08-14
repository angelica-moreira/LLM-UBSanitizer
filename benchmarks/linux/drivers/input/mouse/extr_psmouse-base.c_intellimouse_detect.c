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
typedef  int u8 ;
struct ps2dev {int dummy; } ;
struct psmouse {char* vendor; char* name; int pktsize; TYPE_1__* dev; struct ps2dev ps2dev; } ;
struct TYPE_2__ {int /*<<< orphan*/  relbit; int /*<<< orphan*/  keybit; } ;

/* Variables and functions */
 int /*<<< orphan*/  BTN_MIDDLE ; 
 int ENODEV ; 
 int /*<<< orphan*/  PSMOUSE_CMD_GETID ; 
 int /*<<< orphan*/  PSMOUSE_CMD_SETRATE ; 
 int /*<<< orphan*/  REL_WHEEL ; 
 int /*<<< orphan*/  __set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ps2_command (struct ps2dev*,int*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int intellimouse_detect(struct psmouse *psmouse, bool set_properties)
{
	struct ps2dev *ps2dev = &psmouse->ps2dev;
	u8 param[2];

	param[0] = 200;
	ps2_command(ps2dev, param, PSMOUSE_CMD_SETRATE);
	param[0] = 100;
	ps2_command(ps2dev, param, PSMOUSE_CMD_SETRATE);
	param[0] =  80;
	ps2_command(ps2dev, param, PSMOUSE_CMD_SETRATE);
	ps2_command(ps2dev, param, PSMOUSE_CMD_GETID);

	if (param[0] != 3)
		return -ENODEV;

	if (set_properties) {
		__set_bit(BTN_MIDDLE, psmouse->dev->keybit);
		__set_bit(REL_WHEEL, psmouse->dev->relbit);

		if (!psmouse->vendor)
			psmouse->vendor = "Generic";
		if (!psmouse->name)
			psmouse->name = "Wheel Mouse";
		psmouse->pktsize = 4;
	}

	return 0;
}
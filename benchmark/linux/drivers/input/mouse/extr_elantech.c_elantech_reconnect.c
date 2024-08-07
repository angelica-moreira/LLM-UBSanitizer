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
struct psmouse {int dummy; } ;

/* Variables and functions */
 scalar_t__ elantech_detect (struct psmouse*,int /*<<< orphan*/ ) ; 
 scalar_t__ elantech_set_absolute_mode (struct psmouse*) ; 
 int /*<<< orphan*/  psmouse_err (struct psmouse*,char*) ; 
 int /*<<< orphan*/  psmouse_reset (struct psmouse*) ; 

__attribute__((used)) static int elantech_reconnect(struct psmouse *psmouse)
{
	psmouse_reset(psmouse);

	if (elantech_detect(psmouse, 0))
		return -1;

	if (elantech_set_absolute_mode(psmouse)) {
		psmouse_err(psmouse,
			    "failed to put touchpad back into absolute mode.\n");
		return -1;
	}

	return 0;
}
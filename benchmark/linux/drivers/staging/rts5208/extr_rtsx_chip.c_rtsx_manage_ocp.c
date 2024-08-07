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
struct rtsx_chip {int card_exist; scalar_t__ ocp_int; int /*<<< orphan*/  ocp_stat; } ;

/* Variables and functions */
 int MS_CARD ; 
 int /*<<< orphan*/  OCPSTAT ; 
 int SD_CARD ; 
 int XD_CARD ; 
 int /*<<< orphan*/  ms_power_off_card3v3 (struct rtsx_chip*) ; 
 int /*<<< orphan*/  rtsx_read_register (struct rtsx_chip*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sd_power_off_card3v3 (struct rtsx_chip*) ; 
 int /*<<< orphan*/  xd_power_off_card3v3 (struct rtsx_chip*) ; 

__attribute__((used)) static void rtsx_manage_ocp(struct rtsx_chip *chip)
{
#ifdef SUPPORT_OCP
	if (!chip->ocp_int)
		return;

	rtsx_read_register(chip, OCPSTAT, &chip->ocp_stat);

	if (chip->card_exist & SD_CARD)
		sd_power_off_card3v3(chip);
	else if (chip->card_exist & MS_CARD)
		ms_power_off_card3v3(chip);
	else if (chip->card_exist & XD_CARD)
		xd_power_off_card3v3(chip);

	chip->ocp_int = 0;
#endif
}
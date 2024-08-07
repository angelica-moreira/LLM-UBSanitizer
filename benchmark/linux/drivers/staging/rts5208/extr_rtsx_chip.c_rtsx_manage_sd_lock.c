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
struct sd_info {int sd_lock_notify; void* sd_erase_status; } ;
struct rtsx_chip {int card_exist; int need_reinit; struct sd_info sd_card; } ;

/* Variables and functions */
 int SD_CARD ; 
 void* SD_NOT_ERASE ; 
 int /*<<< orphan*/  rtsx_read_register (struct rtsx_chip*,int,int*) ; 

__attribute__((used)) static void rtsx_manage_sd_lock(struct rtsx_chip *chip)
{
#ifdef SUPPORT_SD_LOCK
	struct sd_info *sd_card = &chip->sd_card;
	u8 val;

	if (!sd_card->sd_erase_status)
		return;

	if (chip->card_exist & SD_CARD) {
		rtsx_read_register(chip, 0xFD30, &val);
		if (val & 0x02) {
			sd_card->sd_erase_status = SD_NOT_ERASE;
			sd_card->sd_lock_notify = 1;
			chip->need_reinit |= SD_CARD;
		}
	} else {
		sd_card->sd_erase_status = SD_NOT_ERASE;
	}
#endif
}
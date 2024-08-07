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
struct bd2802_led {int /*<<< orphan*/  client; int /*<<< orphan*/  rgb_current; int /*<<< orphan*/  adf_on; } ;
typedef  enum led_ids { ____Placeholder_led_ids } led_ids ;
typedef  enum led_colors { ____Placeholder_led_colors } led_colors ;

/* Variables and functions */
 int /*<<< orphan*/  BD2802_CURRENT_000 ; 
 int /*<<< orphan*/  BD2802_ON ; 
 int /*<<< orphan*/  BD2802_PATTERN_FULL ; 
 int /*<<< orphan*/  BD2802_REG_CURRENT1SETUP ; 
 int /*<<< orphan*/  BD2802_REG_CURRENT2SETUP ; 
 int /*<<< orphan*/  BD2802_REG_WAVEPATTERN ; 
 int /*<<< orphan*/  bd2802_enable (struct bd2802_led*,int) ; 
 int /*<<< orphan*/  bd2802_get_reg_addr (int,int,int /*<<< orphan*/ ) ; 
 scalar_t__ bd2802_is_all_off (struct bd2802_led*) ; 
 int /*<<< orphan*/  bd2802_reset_cancel (struct bd2802_led*) ; 
 int /*<<< orphan*/  bd2802_update_state (struct bd2802_led*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bd2802_write_byte (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void bd2802_set_on(struct bd2802_led *led, enum led_ids id,
							enum led_colors color)
{
	u8 reg;

	if (bd2802_is_all_off(led) && !led->adf_on)
		bd2802_reset_cancel(led);

	reg = bd2802_get_reg_addr(id, color, BD2802_REG_CURRENT1SETUP);
	bd2802_write_byte(led->client, reg, led->rgb_current);
	reg = bd2802_get_reg_addr(id, color, BD2802_REG_CURRENT2SETUP);
	bd2802_write_byte(led->client, reg, BD2802_CURRENT_000);
	reg = bd2802_get_reg_addr(id, color, BD2802_REG_WAVEPATTERN);
	bd2802_write_byte(led->client, reg, BD2802_PATTERN_FULL);

	bd2802_enable(led, id);
	bd2802_update_state(led, id, color, BD2802_ON);
}
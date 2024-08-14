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
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_2__ {int /*<<< orphan*/  gpio; } ;
struct ath5k_hw {TYPE_1__ rf_kill; } ;

/* Variables and functions */
 int /*<<< orphan*/  ath5k_hw_get_gpio (struct ath5k_hw*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ath5k_hw_set_gpio_input (struct ath5k_hw*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ath5k_hw_set_gpio_intr (struct ath5k_hw*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline void ath5k_rfkill_set_intr(struct ath5k_hw *ah, bool enable)
{
	u32 curval;

	ath5k_hw_set_gpio_input(ah, ah->rf_kill.gpio);
	curval = ath5k_hw_get_gpio(ah, ah->rf_kill.gpio);
	ath5k_hw_set_gpio_intr(ah, ah->rf_kill.gpio, enable ?
					!!curval : !curval);
}
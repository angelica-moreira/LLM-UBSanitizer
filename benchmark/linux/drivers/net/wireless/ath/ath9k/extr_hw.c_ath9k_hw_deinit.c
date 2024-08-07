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
struct ath_hw {int dummy; } ;
struct ath_common {scalar_t__ state; } ;

/* Variables and functions */
 int /*<<< orphan*/  ATH9K_PM_FULL_SLEEP ; 
 scalar_t__ ATH_HW_INITIALIZED ; 
 struct ath_common* ath9k_hw_common (struct ath_hw*) ; 
 int /*<<< orphan*/  ath9k_hw_setpower (struct ath_hw*,int /*<<< orphan*/ ) ; 

void ath9k_hw_deinit(struct ath_hw *ah)
{
	struct ath_common *common = ath9k_hw_common(ah);

	if (common->state < ATH_HW_INITIALIZED)
		return;

	ath9k_hw_setpower(ah, ATH9K_PM_FULL_SLEEP);
}
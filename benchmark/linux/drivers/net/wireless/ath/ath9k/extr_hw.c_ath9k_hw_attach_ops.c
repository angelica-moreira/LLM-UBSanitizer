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

/* Variables and functions */
 int /*<<< orphan*/  AR_SREV_9300_20_OR_LATER (struct ath_hw*) ; 
 int ar9002_hw_attach_ops (struct ath_hw*) ; 
 int /*<<< orphan*/  ar9003_hw_attach_ops (struct ath_hw*) ; 

__attribute__((used)) static int ath9k_hw_attach_ops(struct ath_hw *ah)
{
	if (!AR_SREV_9300_20_OR_LATER(ah))
		return ar9002_hw_attach_ops(ah);

	ar9003_hw_attach_ops(ah);
	return 0;
}
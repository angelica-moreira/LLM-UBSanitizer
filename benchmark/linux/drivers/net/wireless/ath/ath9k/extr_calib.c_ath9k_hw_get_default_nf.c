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
struct ath_hw {int dummy; } ;
struct ath9k_channel {int dummy; } ;
typedef  scalar_t__ s16 ;
struct TYPE_2__ {scalar_t__ nominal; scalar_t__* cal; } ;

/* Variables and functions */
 TYPE_1__* ath9k_hw_get_nf_limits (struct ath_hw*,struct ath9k_channel*) ; 

__attribute__((used)) static s16 ath9k_hw_get_default_nf(struct ath_hw *ah,
				   struct ath9k_channel *chan,
				   int chain)
{
	s16 calib_nf = ath9k_hw_get_nf_limits(ah, chan)->cal[chain];

	if (calib_nf)
		return calib_nf;
	else
		return ath9k_hw_get_nf_limits(ah, chan)->nominal;
}
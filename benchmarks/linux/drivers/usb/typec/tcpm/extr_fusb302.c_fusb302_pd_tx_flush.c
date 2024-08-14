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
struct fusb302_chip {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  FUSB_REG_CONTROL0 ; 
 int /*<<< orphan*/  FUSB_REG_CONTROL0_TX_FLUSH ; 
 int fusb302_i2c_set_bits (struct fusb302_chip*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int fusb302_pd_tx_flush(struct fusb302_chip *chip)
{
	return fusb302_i2c_set_bits(chip, FUSB_REG_CONTROL0,
				    FUSB_REG_CONTROL0_TX_FLUSH);
}
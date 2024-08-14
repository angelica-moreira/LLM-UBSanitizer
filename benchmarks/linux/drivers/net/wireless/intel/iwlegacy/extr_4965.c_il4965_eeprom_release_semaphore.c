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
struct il_priv {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CSR_HW_IF_CONFIG_REG ; 
 int /*<<< orphan*/  CSR_HW_IF_CONFIG_REG_BIT_EEPROM_OWN_SEM ; 
 int /*<<< orphan*/  il_clear_bit (struct il_priv*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
il4965_eeprom_release_semaphore(struct il_priv *il)
{
	il_clear_bit(il, CSR_HW_IF_CONFIG_REG,
		     CSR_HW_IF_CONFIG_REG_BIT_EEPROM_OWN_SEM);

}
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
struct ipw_priv {int /*<<< orphan*/ * eeprom; } ;

/* Variables and functions */
 size_t EEPROM_MAC_ADDRESS ; 
 int /*<<< orphan*/  ETH_ALEN ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void eeprom_parse_mac(struct ipw_priv *priv, u8 * mac)
{
	memcpy(mac, &priv->eeprom[EEPROM_MAC_ADDRESS], ETH_ALEN);
}
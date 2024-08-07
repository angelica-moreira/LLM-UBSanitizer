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
typedef  int u32 ;
struct enetc_hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MDIO_CFG ; 
 int MDIO_CFG_BSY ; 
 int TIMEOUT ; 
 int /*<<< orphan*/  enetc_mdio_rd_reg ; 
 int readx_poll_timeout (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int,int) ; 

__attribute__((used)) static int enetc_mdio_wait_complete(struct enetc_hw *hw)
{
	u32 val;

	return readx_poll_timeout(enetc_mdio_rd_reg, MDIO_CFG, val,
				  !(val & MDIO_CFG_BSY), 10, 10 * TIMEOUT);
}
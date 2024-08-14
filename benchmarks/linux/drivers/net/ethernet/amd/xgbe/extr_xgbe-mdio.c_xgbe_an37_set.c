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
struct xgbe_prv_data {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MDIO_CTRL1 ; 
 int /*<<< orphan*/  MDIO_MMD_VEND2 ; 
 unsigned int MDIO_VEND2_CTRL1_AN_ENABLE ; 
 unsigned int MDIO_VEND2_CTRL1_AN_RESTART ; 
 unsigned int XMDIO_READ (struct xgbe_prv_data*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XMDIO_WRITE (struct xgbe_prv_data*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 

__attribute__((used)) static void xgbe_an37_set(struct xgbe_prv_data *pdata, bool enable,
			  bool restart)
{
	unsigned int reg;

	reg = XMDIO_READ(pdata, MDIO_MMD_VEND2, MDIO_CTRL1);
	reg &= ~MDIO_VEND2_CTRL1_AN_ENABLE;

	if (enable)
		reg |= MDIO_VEND2_CTRL1_AN_ENABLE;

	if (restart)
		reg |= MDIO_VEND2_CTRL1_AN_RESTART;

	XMDIO_WRITE(pdata, MDIO_MMD_VEND2, MDIO_CTRL1, reg);
}
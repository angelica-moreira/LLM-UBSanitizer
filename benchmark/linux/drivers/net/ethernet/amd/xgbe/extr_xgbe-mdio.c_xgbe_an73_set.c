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
 unsigned int MDIO_AN_CTRL1_ENABLE ; 
 unsigned int MDIO_AN_CTRL1_RESTART ; 
 int /*<<< orphan*/  MDIO_CTRL1 ; 
 int /*<<< orphan*/  MDIO_MMD_AN ; 
 int /*<<< orphan*/  MDIO_MMD_PMAPMD ; 
 int /*<<< orphan*/  MDIO_PMA_10GBR_PMD_CTRL ; 
 unsigned int XGBE_KR_TRAINING_ENABLE ; 
 unsigned int XMDIO_READ (struct xgbe_prv_data*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XMDIO_WRITE (struct xgbe_prv_data*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 

__attribute__((used)) static void xgbe_an73_set(struct xgbe_prv_data *pdata, bool enable,
			  bool restart)
{
	unsigned int reg;

	/* Disable KR training for now */
	reg = XMDIO_READ(pdata, MDIO_MMD_PMAPMD, MDIO_PMA_10GBR_PMD_CTRL);
	reg &= ~XGBE_KR_TRAINING_ENABLE;
	XMDIO_WRITE(pdata, MDIO_MMD_PMAPMD, MDIO_PMA_10GBR_PMD_CTRL, reg);

	/* Update AN settings */
	reg = XMDIO_READ(pdata, MDIO_MMD_AN, MDIO_CTRL1);
	reg &= ~MDIO_AN_CTRL1_ENABLE;

	if (enable)
		reg |= MDIO_AN_CTRL1_ENABLE;

	if (restart)
		reg |= MDIO_AN_CTRL1_RESTART;

	XMDIO_WRITE(pdata, MDIO_MMD_AN, MDIO_CTRL1, reg);
}
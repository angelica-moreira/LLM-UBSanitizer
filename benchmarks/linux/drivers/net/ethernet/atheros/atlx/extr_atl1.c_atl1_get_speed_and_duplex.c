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
typedef  int u16 ;
struct pci_dev {int /*<<< orphan*/  dev; } ;
struct atl1_hw {struct atl1_adapter* back; } ;
struct atl1_adapter {struct pci_dev* pdev; } ;
typedef  scalar_t__ s32 ;

/* Variables and functions */
 scalar_t__ ATLX_ERR_PHY_RES ; 
 scalar_t__ ATLX_ERR_PHY_SPEED ; 
 int FULL_DUPLEX ; 
 int HALF_DUPLEX ; 
 int /*<<< orphan*/  MII_ATLX_PSSR ; 
#define  MII_ATLX_PSSR_1000MBS 130 
#define  MII_ATLX_PSSR_100MBS 129 
#define  MII_ATLX_PSSR_10MBS 128 
 int MII_ATLX_PSSR_DPLX ; 
 int MII_ATLX_PSSR_SPD_DPLX_RESOLVED ; 
 int MII_ATLX_PSSR_SPEED ; 
 int SPEED_10 ; 
 int SPEED_100 ; 
 int SPEED_1000 ; 
 scalar_t__ atl1_read_phy_reg (struct atl1_hw*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  netif_msg_hw (struct atl1_adapter*) ; 

__attribute__((used)) static s32 atl1_get_speed_and_duplex(struct atl1_hw *hw, u16 *speed, u16 *duplex)
{
	struct pci_dev *pdev = hw->back->pdev;
	struct atl1_adapter *adapter = hw->back;
	s32 ret_val;
	u16 phy_data;

	/* ; --- Read   PHY Specific Status Register (17) */
	ret_val = atl1_read_phy_reg(hw, MII_ATLX_PSSR, &phy_data);
	if (ret_val)
		return ret_val;

	if (!(phy_data & MII_ATLX_PSSR_SPD_DPLX_RESOLVED))
		return ATLX_ERR_PHY_RES;

	switch (phy_data & MII_ATLX_PSSR_SPEED) {
	case MII_ATLX_PSSR_1000MBS:
		*speed = SPEED_1000;
		break;
	case MII_ATLX_PSSR_100MBS:
		*speed = SPEED_100;
		break;
	case MII_ATLX_PSSR_10MBS:
		*speed = SPEED_10;
		break;
	default:
		if (netif_msg_hw(adapter))
			dev_dbg(&pdev->dev, "error getting speed\n");
		return ATLX_ERR_PHY_SPEED;
	}
	if (phy_data & MII_ATLX_PSSR_DPLX)
		*duplex = FULL_DUPLEX;
	else
		*duplex = HALF_DUPLEX;

	return 0;
}
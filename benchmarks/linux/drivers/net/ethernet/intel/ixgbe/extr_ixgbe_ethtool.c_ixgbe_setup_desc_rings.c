#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct ixgbe_ring {int /*<<< orphan*/  reg_idx; int /*<<< orphan*/  netdev; int /*<<< orphan*/ * dev; scalar_t__ queue_index; int /*<<< orphan*/  count; } ;
struct TYPE_9__ {int /*<<< orphan*/  (* enable_rx ) (struct ixgbe_hw*) ;int /*<<< orphan*/  (* disable_rx ) (struct ixgbe_hw*) ;} ;
struct TYPE_10__ {int type; TYPE_4__ ops; } ;
struct ixgbe_hw {TYPE_5__ mac; } ;
struct ixgbe_adapter {struct ixgbe_hw hw; TYPE_3__** rx_ring; int /*<<< orphan*/  netdev; TYPE_2__* pdev; TYPE_1__** tx_ring; struct ixgbe_ring test_rx_ring; struct ixgbe_ring test_tx_ring; } ;
struct TYPE_8__ {int /*<<< orphan*/  reg_idx; } ;
struct TYPE_7__ {int /*<<< orphan*/  dev; } ;
struct TYPE_6__ {int /*<<< orphan*/  reg_idx; } ;

/* Variables and functions */
 int /*<<< orphan*/  IXGBE_DEFAULT_RXD ; 
 int /*<<< orphan*/  IXGBE_DEFAULT_TXD ; 
 int /*<<< orphan*/  IXGBE_DMATXCTL ; 
 int /*<<< orphan*/  IXGBE_DMATXCTL_TE ; 
 int /*<<< orphan*/  IXGBE_READ_REG (struct ixgbe_hw*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IXGBE_RXCTRL ; 
 int /*<<< orphan*/  IXGBE_RXCTRL_DMBYPS ; 
 int /*<<< orphan*/  IXGBE_WRITE_REG (struct ixgbe_hw*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ixgbe_configure_rx_ring (struct ixgbe_adapter*,struct ixgbe_ring*) ; 
 int /*<<< orphan*/  ixgbe_configure_tx_ring (struct ixgbe_adapter*,struct ixgbe_ring*) ; 
 int /*<<< orphan*/  ixgbe_free_desc_rings (struct ixgbe_adapter*) ; 
#define  ixgbe_mac_82599EB 132 
#define  ixgbe_mac_X540 131 
#define  ixgbe_mac_X550 130 
#define  ixgbe_mac_X550EM_x 129 
#define  ixgbe_mac_x550em_a 128 
 int ixgbe_setup_rx_resources (struct ixgbe_adapter*,struct ixgbe_ring*) ; 
 int ixgbe_setup_tx_resources (struct ixgbe_ring*) ; 
 int /*<<< orphan*/  stub1 (struct ixgbe_hw*) ; 
 int /*<<< orphan*/  stub2 (struct ixgbe_hw*) ; 

__attribute__((used)) static int ixgbe_setup_desc_rings(struct ixgbe_adapter *adapter)
{
	struct ixgbe_ring *tx_ring = &adapter->test_tx_ring;
	struct ixgbe_ring *rx_ring = &adapter->test_rx_ring;
	struct ixgbe_hw *hw = &adapter->hw;
	u32 rctl, reg_data;
	int ret_val;
	int err;

	/* Setup Tx descriptor ring and Tx buffers */
	tx_ring->count = IXGBE_DEFAULT_TXD;
	tx_ring->queue_index = 0;
	tx_ring->dev = &adapter->pdev->dev;
	tx_ring->netdev = adapter->netdev;
	tx_ring->reg_idx = adapter->tx_ring[0]->reg_idx;

	err = ixgbe_setup_tx_resources(tx_ring);
	if (err)
		return 1;

	switch (adapter->hw.mac.type) {
	case ixgbe_mac_82599EB:
	case ixgbe_mac_X540:
	case ixgbe_mac_X550:
	case ixgbe_mac_X550EM_x:
	case ixgbe_mac_x550em_a:
		reg_data = IXGBE_READ_REG(&adapter->hw, IXGBE_DMATXCTL);
		reg_data |= IXGBE_DMATXCTL_TE;
		IXGBE_WRITE_REG(&adapter->hw, IXGBE_DMATXCTL, reg_data);
		break;
	default:
		break;
	}

	ixgbe_configure_tx_ring(adapter, tx_ring);

	/* Setup Rx Descriptor ring and Rx buffers */
	rx_ring->count = IXGBE_DEFAULT_RXD;
	rx_ring->queue_index = 0;
	rx_ring->dev = &adapter->pdev->dev;
	rx_ring->netdev = adapter->netdev;
	rx_ring->reg_idx = adapter->rx_ring[0]->reg_idx;

	err = ixgbe_setup_rx_resources(adapter, rx_ring);
	if (err) {
		ret_val = 4;
		goto err_nomem;
	}

	hw->mac.ops.disable_rx(hw);

	ixgbe_configure_rx_ring(adapter, rx_ring);

	rctl = IXGBE_READ_REG(&adapter->hw, IXGBE_RXCTRL);
	rctl |= IXGBE_RXCTRL_DMBYPS;
	IXGBE_WRITE_REG(&adapter->hw, IXGBE_RXCTRL, rctl);

	hw->mac.ops.enable_rx(hw);

	return 0;

err_nomem:
	ixgbe_free_desc_rings(adapter);
	return ret_val;
}
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
typedef  int u32 ;

/* Variables and functions */
 int MLXSW_REG_PTYS_ETH_SPEED_100GBASE_CR4 ; 
 int MLXSW_REG_PTYS_ETH_SPEED_100GBASE_KR4 ; 
 int MLXSW_REG_PTYS_ETH_SPEED_100GBASE_SR4 ; 
 int MLXSW_REG_PTYS_ETH_SPEED_10GBASE_CR ; 
 int MLXSW_REG_PTYS_ETH_SPEED_10GBASE_KR ; 
 int MLXSW_REG_PTYS_ETH_SPEED_10GBASE_KX4 ; 
 int MLXSW_REG_PTYS_ETH_SPEED_10GBASE_SR ; 
 int MLXSW_REG_PTYS_ETH_SPEED_40GBASE_CR4 ; 
 int MLXSW_REG_PTYS_ETH_SPEED_40GBASE_KR4 ; 
 int MLXSW_REG_PTYS_ETH_SPEED_40GBASE_SR4 ; 
 int MLXSW_REG_PTYS_ETH_SPEED_SGMII ; 
 int /*<<< orphan*/  PORT_DA ; 
 int /*<<< orphan*/  PORT_FIBRE ; 
 int /*<<< orphan*/  PORT_NONE ; 
 int /*<<< orphan*/  PORT_OTHER ; 

__attribute__((used)) static u8 mlxsw_sx_port_connector_port(u32 ptys_eth_proto)
{
	if (ptys_eth_proto & (MLXSW_REG_PTYS_ETH_SPEED_10GBASE_SR |
			      MLXSW_REG_PTYS_ETH_SPEED_40GBASE_SR4 |
			      MLXSW_REG_PTYS_ETH_SPEED_100GBASE_SR4 |
			      MLXSW_REG_PTYS_ETH_SPEED_SGMII))
		return PORT_FIBRE;

	if (ptys_eth_proto & (MLXSW_REG_PTYS_ETH_SPEED_10GBASE_CR |
			      MLXSW_REG_PTYS_ETH_SPEED_40GBASE_CR4 |
			      MLXSW_REG_PTYS_ETH_SPEED_100GBASE_CR4))
		return PORT_DA;

	if (ptys_eth_proto & (MLXSW_REG_PTYS_ETH_SPEED_10GBASE_KR |
			      MLXSW_REG_PTYS_ETH_SPEED_10GBASE_KX4 |
			      MLXSW_REG_PTYS_ETH_SPEED_40GBASE_KR4 |
			      MLXSW_REG_PTYS_ETH_SPEED_100GBASE_KR4))
		return PORT_NONE;

	return PORT_OTHER;
}
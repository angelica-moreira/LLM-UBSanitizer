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

/* Variables and functions */
 int /*<<< orphan*/  MLXSW_REG_ZERO (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  cwtpm ; 
 int /*<<< orphan*/  mlxsw_reg_cwtpm_ee_set (char*,int) ; 
 int /*<<< orphan*/  mlxsw_reg_cwtpm_ew_set (char*,int) ; 
 int /*<<< orphan*/  mlxsw_reg_cwtpm_local_port_set (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlxsw_reg_cwtpm_ntcp_g_set (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlxsw_reg_cwtpm_ntcp_r_set (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlxsw_reg_cwtpm_ntcp_y_set (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlxsw_reg_cwtpm_tcp_g_set (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlxsw_reg_cwtpm_tcp_r_set (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlxsw_reg_cwtpm_tcp_y_set (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlxsw_reg_cwtpm_traffic_class_set (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void mlxsw_reg_cwtpm_pack(char *payload, u8 local_port,
					u8 traffic_class, u8 profile,
					bool wred, bool ecn)
{
	MLXSW_REG_ZERO(cwtpm, payload);
	mlxsw_reg_cwtpm_local_port_set(payload, local_port);
	mlxsw_reg_cwtpm_traffic_class_set(payload, traffic_class);
	mlxsw_reg_cwtpm_ew_set(payload, wred);
	mlxsw_reg_cwtpm_ee_set(payload, ecn);
	mlxsw_reg_cwtpm_tcp_g_set(payload, profile);
	mlxsw_reg_cwtpm_tcp_y_set(payload, profile);
	mlxsw_reg_cwtpm_tcp_r_set(payload, profile);
	mlxsw_reg_cwtpm_ntcp_g_set(payload, profile);
	mlxsw_reg_cwtpm_ntcp_y_set(payload, profile);
	mlxsw_reg_cwtpm_ntcp_r_set(payload, profile);
}
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
typedef  int /*<<< orphan*/  u32 ;

/* Variables and functions */
 int /*<<< orphan*/  MLXSW_REG_ZERO (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  mlxsw_reg_mpsc_e_set (char*,int) ; 
 int /*<<< orphan*/  mlxsw_reg_mpsc_local_port_set (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlxsw_reg_mpsc_rate_set (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpsc ; 

__attribute__((used)) static inline void mlxsw_reg_mpsc_pack(char *payload, u8 local_port, bool e,
				       u32 rate)
{
	MLXSW_REG_ZERO(mpsc, payload);
	mlxsw_reg_mpsc_local_port_set(payload, local_port);
	mlxsw_reg_mpsc_e_set(payload, e);
	mlxsw_reg_mpsc_rate_set(payload, rate);
}
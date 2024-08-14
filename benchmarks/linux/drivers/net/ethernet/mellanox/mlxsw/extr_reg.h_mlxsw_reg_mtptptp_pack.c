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
typedef  int /*<<< orphan*/  u16 ;
typedef  enum mlxsw_reg_mtptpt_trap_id { ____Placeholder_mlxsw_reg_mtptpt_trap_id } mlxsw_reg_mtptpt_trap_id ;

/* Variables and functions */
 int /*<<< orphan*/  MLXSW_REG_ZERO (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  mlxsw_reg_mtptpt_message_type_set (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlxsw_reg_mtptpt_trap_id_set (char*,int) ; 
 int /*<<< orphan*/  mtptpt ; 

__attribute__((used)) static inline void mlxsw_reg_mtptptp_pack(char *payload,
					  enum mlxsw_reg_mtptpt_trap_id trap_id,
					  u16 message_type)
{
	MLXSW_REG_ZERO(mtptpt, payload);
	mlxsw_reg_mtptpt_trap_id_set(payload, trap_id);
	mlxsw_reg_mtptpt_message_type_set(payload, message_type);
}
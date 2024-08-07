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
struct mlxsw_core {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MLXSW_CMD_MBOX_SIZE ; 
 int /*<<< orphan*/  MLXSW_CMD_OPCODE_QUERY_BOARDINFO ; 
 int mlxsw_cmd_exec_out (struct mlxsw_core*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int mlxsw_cmd_boardinfo(struct mlxsw_core *mlxsw_core,
				      char *out_mbox)
{
	return mlxsw_cmd_exec_out(mlxsw_core, MLXSW_CMD_OPCODE_QUERY_BOARDINFO,
				  0, 0, false, out_mbox, MLXSW_CMD_MBOX_SIZE);
}
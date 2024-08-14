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
typedef  int u8 ;
typedef  int /*<<< orphan*/  u16 ;

/* Variables and functions */
 int /*<<< orphan*/  mlxsw_reg_pagt_acl_id_set (char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlxsw_reg_pagt_multi_set (char*,int,int) ; 
 int mlxsw_reg_pagt_size_get (char*) ; 
 int /*<<< orphan*/  mlxsw_reg_pagt_size_set (char*,int) ; 

__attribute__((used)) static inline void mlxsw_reg_pagt_acl_id_pack(char *payload, int index,
					      u16 acl_id, bool multi)
{
	u8 size = mlxsw_reg_pagt_size_get(payload);

	if (index >= size)
		mlxsw_reg_pagt_size_set(payload, index + 1);
	mlxsw_reg_pagt_multi_set(payload, index, multi);
	mlxsw_reg_pagt_acl_id_set(payload, index, acl_id);
}
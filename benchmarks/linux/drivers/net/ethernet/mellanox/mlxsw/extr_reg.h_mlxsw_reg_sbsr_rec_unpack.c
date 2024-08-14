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
typedef  int /*<<< orphan*/  u32 ;

/* Variables and functions */
 int /*<<< orphan*/  mlxsw_reg_sbsr_rec_buff_occupancy_get (char*,int) ; 
 int /*<<< orphan*/  mlxsw_reg_sbsr_rec_max_buff_occupancy_get (char*,int) ; 

__attribute__((used)) static inline void mlxsw_reg_sbsr_rec_unpack(char *payload, int rec_index,
					     u32 *p_buff_occupancy,
					     u32 *p_max_buff_occupancy)
{
	*p_buff_occupancy =
		mlxsw_reg_sbsr_rec_buff_occupancy_get(payload, rec_index);
	*p_max_buff_occupancy =
		mlxsw_reg_sbsr_rec_max_buff_occupancy_get(payload, rec_index);
}
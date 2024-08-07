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
struct mlx5dr_match_misc2 {int dummy; } ;
struct mlx5dr_match_param {struct mlx5dr_match_misc2 misc2; } ;

/* Variables and functions */
 int /*<<< orphan*/  DR_STE_SET_MASK_V (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct mlx5dr_match_misc2*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  general_purpose ; 
 int /*<<< orphan*/  general_purpose_lookup_field ; 
 int /*<<< orphan*/  metadata_reg_a ; 

__attribute__((used)) static void dr_ste_build_general_purpose_bit_mask(struct mlx5dr_match_param *value,
						  bool inner, u8 *bit_mask)
{
	struct mlx5dr_match_misc2 *misc_2_mask = &value->misc2;

	DR_STE_SET_MASK_V(general_purpose, bit_mask,
			  general_purpose_lookup_field, misc_2_mask,
			  metadata_reg_a);
}
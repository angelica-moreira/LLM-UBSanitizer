#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_4__ {TYPE_1__* hmc_obj; } ;
struct i40e_hw {TYPE_2__ hmc; } ;
typedef  int /*<<< orphan*/  i40e_status ;
typedef  enum i40e_hmc_lan_rsrc_type { ____Placeholder_i40e_hmc_lan_rsrc_type } i40e_hmc_lan_rsrc_type ;
struct TYPE_3__ {scalar_t__ size; } ;

/* Variables and functions */
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static i40e_status i40e_clear_hmc_context(struct i40e_hw *hw,
					u8 *context_bytes,
					enum i40e_hmc_lan_rsrc_type hmc_type)
{
	/* clean the bit array */
	memset(context_bytes, 0, (u32)hw->hmc.hmc_obj[hmc_type].size);

	return 0;
}
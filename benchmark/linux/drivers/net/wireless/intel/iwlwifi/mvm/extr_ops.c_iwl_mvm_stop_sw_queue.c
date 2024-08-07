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
struct iwl_op_mode {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  iwl_mvm_queue_state_change (struct iwl_op_mode*,int,int) ; 

__attribute__((used)) static void iwl_mvm_stop_sw_queue(struct iwl_op_mode *op_mode, int hw_queue)
{
	iwl_mvm_queue_state_change(op_mode, hw_queue, false);
}
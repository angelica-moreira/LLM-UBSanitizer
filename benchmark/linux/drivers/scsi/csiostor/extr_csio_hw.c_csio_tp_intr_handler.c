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
struct intr_info {int member_0; char* member_1; int member_2; int member_3; } ;
struct csio_hw {int dummy; } ;

/* Variables and functions */
#define  FLMTXFLSTEMPTY_F 128 
 int /*<<< orphan*/  TP_INT_CAUSE_A ; 
 scalar_t__ csio_handle_intr_status (struct csio_hw*,int /*<<< orphan*/ ,struct intr_info*) ; 
 int /*<<< orphan*/  csio_hw_fatal_err (struct csio_hw*) ; 

__attribute__((used)) static void csio_tp_intr_handler(struct csio_hw *hw)
{
	static struct intr_info tp_intr_info[] = {
		{ 0x3fffffff, "TP parity error", -1, 1 },
		{ FLMTXFLSTEMPTY_F, "TP out of Tx pages", -1, 1 },
		{ 0, NULL, 0, 0 }
	};

	if (csio_handle_intr_status(hw, TP_INT_CAUSE_A, tp_intr_info))
		csio_hw_fatal_err(hw);
}
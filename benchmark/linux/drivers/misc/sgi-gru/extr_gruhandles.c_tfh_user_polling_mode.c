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
struct gru_tlb_fault_handle {int /*<<< orphan*/  opc; } ;

/* Variables and functions */
 int /*<<< orphan*/  TFHOP_USER_POLLING_MODE ; 
 int /*<<< orphan*/  start_instruction (struct gru_tlb_fault_handle*) ; 

void tfh_user_polling_mode(struct gru_tlb_fault_handle *tfh)
{
	tfh->opc = TFHOP_USER_POLLING_MODE;
	start_instruction(tfh);
}
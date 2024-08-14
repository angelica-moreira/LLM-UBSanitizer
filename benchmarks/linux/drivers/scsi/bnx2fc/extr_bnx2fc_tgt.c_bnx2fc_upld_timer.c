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
struct timer_list {int dummy; } ;
struct bnx2fc_rport {int /*<<< orphan*/  upld_wait; int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  BNX2FC_FLAG_ENABLED ; 
 int /*<<< orphan*/  BNX2FC_FLAG_OFFLOADED ; 
 int /*<<< orphan*/  BNX2FC_FLAG_UPLD_REQ_COMPL ; 
 int /*<<< orphan*/  BNX2FC_TGT_DBG (struct bnx2fc_rport*,char*) ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct bnx2fc_rport* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct bnx2fc_rport* tgt ; 
 int /*<<< orphan*/  upld_timer ; 
 int /*<<< orphan*/  wake_up_interruptible (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void bnx2fc_upld_timer(struct timer_list *t)
{

	struct bnx2fc_rport *tgt = from_timer(tgt, t, upld_timer);

	BNX2FC_TGT_DBG(tgt, "upld_timer - Upload compl not received!!\n");
	/* fake upload completion */
	clear_bit(BNX2FC_FLAG_OFFLOADED, &tgt->flags);
	clear_bit(BNX2FC_FLAG_ENABLED, &tgt->flags);
	set_bit(BNX2FC_FLAG_UPLD_REQ_COMPL, &tgt->flags);
	wake_up_interruptible(&tgt->upld_wait);
}
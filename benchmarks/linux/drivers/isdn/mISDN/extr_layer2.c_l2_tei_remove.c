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
struct layer2 {int /*<<< orphan*/  t203; int /*<<< orphan*/  tei; int /*<<< orphan*/  ui_queue; int /*<<< orphan*/  i_queue; } ;
struct FsmInst {struct layer2* userdata; } ;

/* Variables and functions */
 int /*<<< orphan*/  DL_RELEASE_IND ; 
 int /*<<< orphan*/  GROUP_TEI ; 
 int /*<<< orphan*/  ST_L2_1 ; 
 int /*<<< orphan*/  freewin (struct layer2*) ; 
 int /*<<< orphan*/  l2up_create (struct layer2*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mISDN_FsmChangeState (struct FsmInst*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mISDN_FsmDelTimer (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  skb_queue_purge (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stop_t200 (struct layer2*,int) ; 

__attribute__((used)) static void
l2_tei_remove(struct FsmInst *fi, int event, void *arg)
{
	struct layer2 *l2 = fi->userdata;

	skb_queue_purge(&l2->i_queue);
	skb_queue_purge(&l2->ui_queue);
	freewin(l2);
	l2->tei = GROUP_TEI;
	stop_t200(l2, 17);
	mISDN_FsmDelTimer(&l2->t203, 19);
	l2up_create(l2, DL_RELEASE_IND, 0, NULL);
/*	mISDN_queue_data(&l2->inst, l2->inst.id | MSG_BROADCAST,
 *		MGR_SHORTSTATUS_IND, SSTATUS_L2_RELEASED,
 *		0, NULL, 0);
 */
	mISDN_FsmChangeState(fi, ST_L2_1);
}
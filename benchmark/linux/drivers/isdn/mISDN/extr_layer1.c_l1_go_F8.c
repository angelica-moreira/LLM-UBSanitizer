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
struct FsmInst {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ST_L1_F8 ; 
 int /*<<< orphan*/  mISDN_FsmChangeState (struct FsmInst*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
l1_go_F8(struct FsmInst *fi, int event, void *arg)
{
	mISDN_FsmChangeState(fi, ST_L1_F8);
}
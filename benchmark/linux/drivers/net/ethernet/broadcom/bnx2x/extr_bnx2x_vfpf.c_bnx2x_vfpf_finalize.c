#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  type; } ;
struct vfpf_first_tlv {TYPE_1__ tl; } ;
struct bnx2x {int /*<<< orphan*/  vf2pf_mutex; } ;

/* Variables and functions */
 int /*<<< orphan*/  BNX2X_MSG_IOV ; 
 int /*<<< orphan*/  DP (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void bnx2x_vfpf_finalize(struct bnx2x *bp,
				struct vfpf_first_tlv *first_tlv)
{
	DP(BNX2X_MSG_IOV, "done sending [%d] tlv over vf pf channel\n",
	   first_tlv->tl.type);

	mutex_unlock(&bp->vf2pf_mutex);
}
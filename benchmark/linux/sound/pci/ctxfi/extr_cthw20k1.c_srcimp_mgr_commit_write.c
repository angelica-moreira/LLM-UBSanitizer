#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {scalar_t__ srcimap; } ;
struct TYPE_6__ {TYPE_2__ bf; } ;
struct TYPE_4__ {int idx; int /*<<< orphan*/  srcaim; } ;
struct srcimp_mgr_ctrl_blk {TYPE_3__ dirty; TYPE_1__ srcimap; } ;
struct hw {int dummy; } ;

/* Variables and functions */
 scalar_t__ SRCIMAP ; 
 int /*<<< orphan*/  hw_write_20kx (struct hw*,scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int srcimp_mgr_commit_write(struct hw *hw, void *blk)
{
	struct srcimp_mgr_ctrl_blk *ctl = blk;

	if (ctl->dirty.bf.srcimap) {
		hw_write_20kx(hw, SRCIMAP+ctl->srcimap.idx*0x100,
						ctl->srcimap.srcaim);
		ctl->dirty.bf.srcimap = 0;
	}

	return 0;
}
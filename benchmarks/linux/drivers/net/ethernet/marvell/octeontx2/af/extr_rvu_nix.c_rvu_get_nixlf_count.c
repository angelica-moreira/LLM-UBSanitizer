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
struct TYPE_4__ {int max; } ;
struct rvu_block {TYPE_2__ lf; } ;
struct rvu {TYPE_1__* hw; } ;
struct TYPE_3__ {struct rvu_block* block; } ;

/* Variables and functions */
 int /*<<< orphan*/  BLKTYPE_NIX ; 
 int rvu_get_blkaddr (struct rvu*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int rvu_get_nixlf_count(struct rvu *rvu)
{
	struct rvu_block *block;
	int blkaddr;

	blkaddr = rvu_get_blkaddr(rvu, BLKTYPE_NIX, 0);
	if (blkaddr < 0)
		return 0;
	block = &rvu->hw->block[blkaddr];
	return block->lf.max;
}
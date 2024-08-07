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
struct TYPE_3__ {int srtctl; } ;
struct TYPE_4__ {TYPE_1__ bf; } ;
struct dai_ctrl_blk {TYPE_2__ dirty; int /*<<< orphan*/  srtctl; } ;

/* Variables and functions */
 int /*<<< orphan*/  SRTCTL_SRCR ; 
 int /*<<< orphan*/  set_field (int /*<<< orphan*/ *,int /*<<< orphan*/ ,unsigned int) ; 

__attribute__((used)) static int dai_srt_set_srcr(void *blk, unsigned int src)
{
	struct dai_ctrl_blk *ctl = blk;

	set_field(&ctl->srtctl, SRTCTL_SRCR, src);
	ctl->dirty.bf.srtctl = 1;
	return 0;
}
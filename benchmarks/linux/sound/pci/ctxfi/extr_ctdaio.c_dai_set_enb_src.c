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
struct dai {int /*<<< orphan*/  ctrl_blk; TYPE_1__* hw; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* dai_srt_set_ec ) (int /*<<< orphan*/ ,unsigned int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,unsigned int) ; 

__attribute__((used)) static int dai_set_enb_src(struct dai *dai, unsigned int enb)
{
	dai->hw->dai_srt_set_ec(dai->ctrl_blk, enb);
	return 0;
}
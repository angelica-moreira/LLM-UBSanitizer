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

/* Variables and functions */
 int /*<<< orphan*/  IMCR_L2WBAR ; 
 int /*<<< orphan*/  IMCR_L2WWC ; 
 int /*<<< orphan*/  cache_block_operation_nowait (unsigned int*,unsigned int*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void L2_cache_block_writeback_nowait(unsigned int start, unsigned int end)
{
	cache_block_operation_nowait((unsigned int *) start,
				     (unsigned int *) end,
				     IMCR_L2WBAR, IMCR_L2WWC);
}
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
struct bnx2x_fastpath {scalar_t__ mode; int /*<<< orphan*/  page_pool; } ;
struct bnx2x {int dummy; } ;

/* Variables and functions */
 scalar_t__ TPA_MODE_DISABLED ; 
 int /*<<< orphan*/  bnx2x_free_rx_mem_pool (struct bnx2x*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bnx2x_free_rx_sge (struct bnx2x*,struct bnx2x_fastpath*,int) ; 

__attribute__((used)) static inline void bnx2x_free_rx_sge_range(struct bnx2x *bp,
					   struct bnx2x_fastpath *fp, int last)
{
	int i;

	if (fp->mode == TPA_MODE_DISABLED)
		return;

	for (i = 0; i < last; i++)
		bnx2x_free_rx_sge(bp, fp, i);

	bnx2x_free_rx_mem_pool(bp, &fp->page_pool);
}
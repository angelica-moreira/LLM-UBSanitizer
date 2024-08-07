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
typedef  int /*<<< orphan*/  u32 ;
struct mtk_hsdma_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  mtk_dma_rmw (struct mtk_hsdma_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void mtk_dma_clr(struct mtk_hsdma_device *hsdma, u32 reg, u32 val)
{
	mtk_dma_rmw(hsdma, reg, val, 0);
}
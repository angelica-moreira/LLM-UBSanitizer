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
typedef  scalar_t__ u32 ;
struct mtk_cryp {scalar_t__ base; } ;

/* Variables and functions */
 scalar_t__ readl_relaxed (scalar_t__) ; 

__attribute__((used)) static inline u32 mtk_sha_read(struct mtk_cryp *cryp, u32 offset)
{
	return readl_relaxed(cryp->base + offset);
}
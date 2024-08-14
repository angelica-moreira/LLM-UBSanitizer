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
struct rq_wb {scalar_t__ wb_normal; } ;

/* Variables and functions */

__attribute__((used)) static inline bool rwb_enabled(struct rq_wb *rwb)
{
	return rwb && rwb->wb_normal != 0;
}
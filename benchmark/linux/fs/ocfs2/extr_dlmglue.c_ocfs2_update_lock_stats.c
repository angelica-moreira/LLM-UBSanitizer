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
struct ocfs2_mask_waiter {int dummy; } ;
struct ocfs2_lock_res {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline void ocfs2_update_lock_stats(struct ocfs2_lock_res *res,
			   int level, struct ocfs2_mask_waiter *mw, int ret)
{
}
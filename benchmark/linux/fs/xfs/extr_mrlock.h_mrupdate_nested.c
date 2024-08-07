#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int mr_writer; int /*<<< orphan*/  mr_lock; } ;
typedef  TYPE_1__ mrlock_t ;

/* Variables and functions */
 int /*<<< orphan*/  down_write_nested (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static inline void mrupdate_nested(mrlock_t *mrp, int subclass)
{
	down_write_nested(&mrp->mr_lock, subclass);
#if defined(DEBUG) || defined(XFS_WARN)
	mrp->mr_writer = 1;
#endif
}
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
struct cxio_rdev {int dummy; } ;

/* Variables and functions */
 int __cxio_tpt_op (struct cxio_rdev*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned long long,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int cxio_deallocate_window(struct cxio_rdev *rdev_p, u32 stag)
{
	return __cxio_tpt_op(rdev_p, 1, &stag, 0, 0, 0, 0, 0, 0ULL, 0, 0,
			     0, 0);
}
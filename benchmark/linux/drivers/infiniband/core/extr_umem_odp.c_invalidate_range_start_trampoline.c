#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
struct TYPE_6__ {TYPE_2__* ibdev; } ;
struct ib_umem_odp {TYPE_3__ umem; } ;
struct TYPE_4__ {int /*<<< orphan*/  (* invalidate_range ) (struct ib_umem_odp*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;} ;
struct TYPE_5__ {TYPE_1__ ops; } ;

/* Variables and functions */
 int /*<<< orphan*/  ib_umem_notifier_start_account (struct ib_umem_odp*) ; 
 int /*<<< orphan*/  stub1 (struct ib_umem_odp*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int invalidate_range_start_trampoline(struct ib_umem_odp *item,
					     u64 start, u64 end, void *cookie)
{
	ib_umem_notifier_start_account(item);
	item->umem.ibdev->ops.invalidate_range(item, start, end);
	return 0;
}
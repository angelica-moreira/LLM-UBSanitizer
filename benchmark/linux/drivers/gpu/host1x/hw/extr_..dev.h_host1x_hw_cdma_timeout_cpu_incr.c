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
typedef  int /*<<< orphan*/  u32 ;
struct host1x_cdma {int dummy; } ;
struct host1x {TYPE_1__* cdma_op; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* timeout_cpu_incr ) (struct host1x_cdma*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct host1x_cdma*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void host1x_hw_cdma_timeout_cpu_incr(struct host1x *host,
						   struct host1x_cdma *cdma,
						   u32 getptr,
						   u32 syncpt_incrs,
						   u32 syncval, u32 nr_slots)
{
	host->cdma_op->timeout_cpu_incr(cdma, getptr, syncpt_incrs, syncval,
					nr_slots);
}
#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct intel_uncore_box {TYPE_2__* pmu; } ;
struct TYPE_4__ {TYPE_1__* type; } ;
struct TYPE_3__ {int perf_ctr_bits; } ;

/* Variables and functions */

__attribute__((used)) static inline int uncore_perf_ctr_bits(struct intel_uncore_box *box)
{
	return box->pmu->type->perf_ctr_bits;
}
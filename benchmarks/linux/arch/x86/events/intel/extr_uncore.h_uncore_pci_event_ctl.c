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
struct intel_uncore_box {TYPE_2__* pmu; int /*<<< orphan*/  flags; } ;
struct TYPE_4__ {TYPE_1__* type; } ;
struct TYPE_3__ {int event_ctl; } ;

/* Variables and functions */
 int /*<<< orphan*/  UNCORE_BOX_FLAG_CTL_OFFS8 ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline
unsigned uncore_pci_event_ctl(struct intel_uncore_box *box, int idx)
{
	if (test_bit(UNCORE_BOX_FLAG_CTL_OFFS8, &box->flags))
		return idx * 8 + box->pmu->type->event_ctl;

	return idx * 4 + box->pmu->type->event_ctl;
}
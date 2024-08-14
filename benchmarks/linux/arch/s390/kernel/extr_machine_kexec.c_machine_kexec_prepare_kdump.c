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
struct TYPE_2__ {scalar_t__ start; scalar_t__ end; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ MACHINE_IS_VM ; 
 int /*<<< orphan*/  PFN_DOWN (scalar_t__) ; 
 TYPE_1__ crashk_res ; 
 int /*<<< orphan*/  diag10_range (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int machine_kexec_prepare_kdump(void)
{
#ifdef CONFIG_CRASH_DUMP
	if (MACHINE_IS_VM)
		diag10_range(PFN_DOWN(crashk_res.start),
			     PFN_DOWN(crashk_res.end - crashk_res.start + 1));
	return 0;
#else
	return -EINVAL;
#endif
}
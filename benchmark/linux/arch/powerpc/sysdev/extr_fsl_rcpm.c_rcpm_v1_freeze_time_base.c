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
struct TYPE_2__ {int /*<<< orphan*/  ctbenr; } ;

/* Variables and functions */
 int /*<<< orphan*/  rcpm_common_freeze_time_base (int /*<<< orphan*/ *,int) ; 
 TYPE_1__* rcpm_v1_regs ; 

__attribute__((used)) static void rcpm_v1_freeze_time_base(bool freeze)
{
	rcpm_common_freeze_time_base(&rcpm_v1_regs->ctbenr, freeze);
}
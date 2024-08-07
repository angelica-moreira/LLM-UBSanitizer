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
struct TYPE_2__ {int /*<<< orphan*/  (* set_priority ) (int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  LOWEST_PRIORITY ; 
 TYPE_1__* icp_ops ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xics_default_distrib_server ; 
 int /*<<< orphan*/  xics_set_cpu_giq (int /*<<< orphan*/ ,int) ; 

void xics_setup_cpu(void)
{
	icp_ops->set_priority(LOWEST_PRIORITY);

	xics_set_cpu_giq(xics_default_distrib_server, 1);
}
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
struct TYPE_2__ {unsigned int cl_idle_timeout_ms; } ;

/* Variables and functions */
 TYPE_1__* o2nm_single_cluster ; 

__attribute__((used)) static inline unsigned int o2net_idle_timeout(void)
{
	return o2nm_single_cluster->cl_idle_timeout_ms;
}
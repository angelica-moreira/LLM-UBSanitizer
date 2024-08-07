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
struct TYPE_2__ {int (* stop_script ) () ;} ;

/* Variables and functions */
 int /*<<< orphan*/  pr_debug (char*) ; 
 TYPE_1__* scripting_ops ; 
 int stub1 () ; 

__attribute__((used)) static int cleanup_scripting(void)
{
	pr_debug("\nperf script stopped\n");

	return scripting_ops ? scripting_ops->stop_script() : 0;
}
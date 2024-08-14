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
typedef  int /*<<< orphan*/  u64 ;
struct TYPE_2__ {int /*<<< orphan*/  (* process_stat_interval ) (int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 TYPE_1__* scripting_ops ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void process_stat_interval(u64 tstamp)
{
	if (scripting_ops && scripting_ops->process_stat_interval)
		scripting_ops->process_stat_interval(tstamp);
}
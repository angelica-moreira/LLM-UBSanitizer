#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
struct auxtrace_record {int /*<<< orphan*/  (* reference ) (struct auxtrace_record*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct auxtrace_record*) ; 

u64 auxtrace_record__reference(struct auxtrace_record *itr)
{
	if (itr)
		return itr->reference(itr);
	return 0;
}
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
struct gru_control_block_status {int istatus; } ;

/* Variables and functions */
 int CBS_EXCEPTION ; 
 int gru_retry_exception (void*) ; 
 int /*<<< orphan*/  rmb () ; 

int gru_check_status_proc(void *cb)
{
	struct gru_control_block_status *gen = (void *)cb;
	int ret;

	ret = gen->istatus;
	if (ret == CBS_EXCEPTION)
		ret = gru_retry_exception(cb);
	rmb();
	return ret;

}
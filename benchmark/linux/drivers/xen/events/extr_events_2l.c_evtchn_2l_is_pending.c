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
struct shared_info {int /*<<< orphan*/ * evtchn_pending; } ;

/* Variables and functions */
 int /*<<< orphan*/  BM (int /*<<< orphan*/ *) ; 
 struct shared_info* HYPERVISOR_shared_info ; 
 int sync_test_bit (unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool evtchn_2l_is_pending(unsigned port)
{
	struct shared_info *s = HYPERVISOR_shared_info;
	return sync_test_bit(port, BM(&s->evtchn_pending[0]));
}
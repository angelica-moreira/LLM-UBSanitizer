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

/* Variables and functions */
 int /*<<< orphan*/  rds_loop_net_ops ; 
 int register_pernet_device (int /*<<< orphan*/ *) ; 

int rds_loop_net_init(void)
{
	return register_pernet_device(&rds_loop_net_ops);
}
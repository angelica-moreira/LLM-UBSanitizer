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
struct knav_range_info {int dummy; } ;
struct knav_queue_inst {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  knav_queue_free_irq (struct knav_queue_inst*) ; 

__attribute__((used)) static int knav_gp_close_queue(struct knav_range_info *range,
				struct knav_queue_inst *inst)
{
	knav_queue_free_irq(inst);
	return 0;
}
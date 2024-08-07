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
struct mapped_device {int /*<<< orphan*/  queue; } ;

/* Variables and functions */
 int blk_mq_queue_inflight (int /*<<< orphan*/ ) ; 
 int md_in_flight_bios (struct mapped_device*) ; 
 scalar_t__ queue_is_mq (int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool md_in_flight(struct mapped_device *md)
{
	if (queue_is_mq(md->queue))
		return blk_mq_queue_inflight(md->queue);
	else
		return md_in_flight_bios(md);
}
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
struct request_queue {int dummy; } ;
struct bio {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __blk_queue_split (struct request_queue*,struct bio**,unsigned int*) ; 

void blk_queue_split(struct request_queue *q, struct bio **bio)
{
	unsigned int nr_segs;

	__blk_queue_split(q, bio, &nr_segs);
}
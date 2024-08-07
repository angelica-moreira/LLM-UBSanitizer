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
struct videobuf_queue {int dummy; } ;

/* Variables and functions */
 int __videobuf_read_start (struct videobuf_queue*) ; 
 int /*<<< orphan*/  videobuf_queue_lock (struct videobuf_queue*) ; 
 int /*<<< orphan*/  videobuf_queue_unlock (struct videobuf_queue*) ; 

int videobuf_read_start(struct videobuf_queue *q)
{
	int rc;

	videobuf_queue_lock(q);
	rc = __videobuf_read_start(q);
	videobuf_queue_unlock(q);

	return rc;
}
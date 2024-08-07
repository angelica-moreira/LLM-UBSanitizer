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
struct camif_vp {int /*<<< orphan*/  active_buffers; int /*<<< orphan*/  active_buf_q; } ;
struct camif_buffer {int /*<<< orphan*/  list; } ;

/* Variables and functions */
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void camif_active_queue_add(struct camif_vp *vp,
					  struct camif_buffer *buf)
{
	list_add_tail(&buf->list, &vp->active_buf_q);
	vp->active_buffers++;
}
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
struct xsk_queue {int /*<<< orphan*/  cons_tail; } ;

/* Variables and functions */

__attribute__((used)) static inline void xskq_discard_desc(struct xsk_queue *q)
{
	q->cons_tail++;
}
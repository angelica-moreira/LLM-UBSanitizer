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
struct smq_policy {int dummy; } ;
struct entry {int sentinel; int pending_work; int /*<<< orphan*/  allocated; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 

__attribute__((used)) static void mark_pending(struct smq_policy *mq, struct entry *e)
{
	BUG_ON(e->sentinel);
	BUG_ON(!e->allocated);
	BUG_ON(e->pending_work);
	e->pending_work = true;
}
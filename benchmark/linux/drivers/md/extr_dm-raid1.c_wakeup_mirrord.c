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
struct mirror_set {int /*<<< orphan*/  kmirrord_work; int /*<<< orphan*/  kmirrord_wq; } ;

/* Variables and functions */
 int /*<<< orphan*/  queue_work (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void wakeup_mirrord(void *context)
{
	struct mirror_set *ms = context;

	queue_work(ms->kmirrord_wq, &ms->kmirrord_work);
}
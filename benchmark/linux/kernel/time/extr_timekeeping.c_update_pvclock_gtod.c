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
struct timekeeper {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  pvclock_gtod_chain ; 
 int /*<<< orphan*/  raw_notifier_call_chain (int /*<<< orphan*/ *,int,struct timekeeper*) ; 

__attribute__((used)) static void update_pvclock_gtod(struct timekeeper *tk, bool was_set)
{
	raw_notifier_call_chain(&pvclock_gtod_chain, was_set, tk);
}
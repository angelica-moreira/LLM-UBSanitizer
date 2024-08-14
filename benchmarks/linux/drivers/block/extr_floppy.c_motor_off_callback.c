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
struct timer_list {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  FDC (unsigned long) ; 
 unsigned long N_DRIVE ; 
 int UNIT (unsigned long) ; 
 scalar_t__ WARN_ON_ONCE (int) ; 
 struct timer_list* motor_off_timer ; 
 int /*<<< orphan*/  set_dor (int /*<<< orphan*/ ,unsigned char,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void motor_off_callback(struct timer_list *t)
{
	unsigned long nr = t - motor_off_timer;
	unsigned char mask = ~(0x10 << UNIT(nr));

	if (WARN_ON_ONCE(nr >= N_DRIVE))
		return;

	set_dor(FDC(nr), mask, 0);
}
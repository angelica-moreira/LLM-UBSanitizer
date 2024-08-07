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
struct k_itimer {struct k_clock* kclock; } ;
struct k_clock {int (* timer_del ) (struct k_itimer*) ;} ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ WARN_ON_ONCE (int) ; 
 int stub1 (struct k_itimer*) ; 

__attribute__((used)) static inline int timer_delete_hook(struct k_itimer *timer)
{
	const struct k_clock *kc = timer->kclock;

	if (WARN_ON_ONCE(!kc || !kc->timer_del))
		return -EINVAL;
	return kc->timer_del(timer);
}
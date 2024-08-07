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
struct net {int dummy; } ;
struct fib_notifier_info {int /*<<< orphan*/  family; } ;
typedef  enum fib_event_type { ____Placeholder_fib_event_type } fib_event_type ;

/* Variables and functions */
 int /*<<< orphan*/  AF_INET6 ; 
 int call_fib_notifiers (struct net*,int,struct fib_notifier_info*) ; 

int call_fib6_notifiers(struct net *net, enum fib_event_type event_type,
			struct fib_notifier_info *info)
{
	info->family = AF_INET6;
	return call_fib_notifiers(net, event_type, info);
}
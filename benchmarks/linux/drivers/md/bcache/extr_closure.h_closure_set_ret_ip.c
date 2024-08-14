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
struct closure {int /*<<< orphan*/  ip; } ;

/* Variables and functions */
 int /*<<< orphan*/  _RET_IP_ ; 

__attribute__((used)) static inline void closure_set_ret_ip(struct closure *cl)
{
#ifdef CONFIG_BCACHE_CLOSURES_DEBUG
	cl->ip = _RET_IP_;
#endif
}
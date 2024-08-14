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
struct ip_vs_conn {int flags; int /*<<< orphan*/  timer; int /*<<< orphan*/  refcnt; } ;

/* Variables and functions */
 int IP_VS_CONN_F_ONE_PACKET ; 
 int /*<<< orphan*/  __ip_vs_conn_put_timer (struct ip_vs_conn*) ; 
 int /*<<< orphan*/  ip_vs_conn_expire (int /*<<< orphan*/ *) ; 
 int refcount_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  timer_pending (int /*<<< orphan*/ *) ; 

void ip_vs_conn_put(struct ip_vs_conn *cp)
{
	if ((cp->flags & IP_VS_CONN_F_ONE_PACKET) &&
	    (refcount_read(&cp->refcnt) == 1) &&
	    !timer_pending(&cp->timer))
		/* expire connection immediately */
		ip_vs_conn_expire(&cp->timer);
	else
		__ip_vs_conn_put_timer(cp);
}
#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct cfpkt {int dummy; } ;
struct TYPE_2__ {int priority; } ;

/* Variables and functions */
 TYPE_1__* pkt_to_skb (struct cfpkt*) ; 

void cfpkt_set_prio(struct cfpkt *pkt, int prio)
{
	pkt_to_skb(pkt)->priority = prio;
}
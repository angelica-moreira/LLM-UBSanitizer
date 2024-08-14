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
struct sk_buff {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  trace_drop_common (struct sk_buff*,void*) ; 

__attribute__((used)) static void trace_kfree_skb_hit(void *ignore, struct sk_buff *skb, void *location)
{
	trace_drop_common(skb, location);
}
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

/* Variables and functions */
 int /*<<< orphan*/  WARN_ONCE (int,char*) ; 
 int /*<<< orphan*/  kfree_skb (void*) ; 

__attribute__((used)) static int ieee80211_free_ack_frame(int id, void *p, void *data)
{
	WARN_ONCE(1, "Have pending ack frames!\n");
	kfree_skb(p);
	return 0;
}
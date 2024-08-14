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
struct sta_info {int /*<<< orphan*/  addr; struct sta_info* hnext; } ;
struct ap_data {struct sta_info** sta_hash; } ;

/* Variables and functions */
 size_t STA_HASH (int /*<<< orphan*/ ) ; 
 scalar_t__ ether_addr_equal (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printk (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void ap_sta_hash_del(struct ap_data *ap, struct sta_info *sta)
{
	struct sta_info *s;

	s = ap->sta_hash[STA_HASH(sta->addr)];
	if (s == NULL) return;
	if (ether_addr_equal(s->addr, sta->addr)) {
		ap->sta_hash[STA_HASH(sta->addr)] = s->hnext;
		return;
	}

	while (s->hnext != NULL && !ether_addr_equal(s->hnext->addr, sta->addr))
		s = s->hnext;
	if (s->hnext != NULL)
		s->hnext = s->hnext->hnext;
	else
		printk("AP: could not remove STA %pM from hash table\n",
		       sta->addr);
}
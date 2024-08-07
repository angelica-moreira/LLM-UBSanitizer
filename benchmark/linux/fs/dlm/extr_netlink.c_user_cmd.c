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
struct genl_info {int /*<<< orphan*/  snd_portid; } ;

/* Variables and functions */
 int /*<<< orphan*/  listener_nlportid ; 
 int /*<<< orphan*/  printk (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int user_cmd(struct sk_buff *skb, struct genl_info *info)
{
	listener_nlportid = info->snd_portid;
	printk("user_cmd nlpid %u\n", listener_nlportid);
	return 0;
}